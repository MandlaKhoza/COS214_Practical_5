#include "EmergencyResponseFacade.h"

#include "OperatorConsole.h"
#include "ResponseMediator.h"
#include "AlertService.h"
#include "Incident.h"
#include "AreaComponent.h"
#include "ResponseComponent.h"

#include "DispatchUnitCommand.h"
#include "LockAreaCommand.h"
#include "IssueAlertCommand.h"
#include "CancelActionCommand.h"

    /**
     * @brief Constructs an EmergencyResponseFacade.
     *
     * @param console The operator console used to execute emergency commands.
     * @param coordinator The mediator responsible for coordinating response components.
     * @param alertService The service responsible for issuing emergency alerts.
     */
EmergencyResponseFacade::EmergencyResponseFacade(
    OperatorConsole* console,
    ResponseMediator* coordinator,
    AlertService* alertService
) {
    this->console = console;
    this->coordinator = coordinator;
    this->alertService = alertService;
} 
    /**
     * @brief Declares an emergency and coordinates the required response actions.
     *
     * Dispatches the specified response unit, locks the affected area,
     * and issues a high-priority emergency alert through the command system.
     *
     * @param incident The incident for which the emergency is being declared.
     * @param area The campus area affected by the emergency.
     * @param unit The response component that should respond to the incident.
     */
void EmergencyResponseFacade::declareEmergency(
    Incident* incident,
    AreaComponent* area,
    ResponseComponent* unit
) {

    if (incident == nullptr || area == nullptr || unit == nullptr || console == nullptr || alertService == nullptr)
    {
        return;
    }

    coordinator->notify(unit, "emergencyDeclared");

    DispatchUnitCommand* dispatch = new DispatchUnitCommand(unit, incident);

    LockAreaCommand* lock = new LockAreaCommand(area);

    IssueAlertCommand* alert = new IssueAlertCommand(alertService, "Emergency reported: " + incident->getDescription(), "HIGH");

    console->executeCommand(dispatch);
    console->executeCommand(lock);
    console->executeCommand(alert);
    incident->contain();
}
    /**
     * @brief Cancels an active emergency response.
     *
     * Reverses the previously executed emergency actions and cancels
     * the associated incident.
     *
     * @param incident The incident whose emergency response should be cancelled.
     */
void EmergencyResponseFacade::cancelEmergency(Incident* incident) {

    if (incident == nullptr || console == nullptr || coordinator == nullptr)
    {
        return;
    }

    // 1. Undo the three commands declareEmergency() issued, in reverse.
    //    undoLast() pops IssueAlertCommand, then LockAreaCommand,
    //    then DispatchUnitCommand. Each undo reverses its own effect
    //    (retract alert, unlock area, stand unit down).
    console->undoLast();
    console->undoLast();
    console->undoLast();

    // 2. Cancel the incident. Depending on its current state
    //    (Active, Dispatched, or Reported), cancel() transitions it
    //    to Cancelled.
    CancelActionCommand* cancel = new CancelActionCommand(incident);
    console->executeCommand(cancel);

    // 3. Tell the mediator to stand everyone down.
    coordinator->notify(nullptr, "emergencyCancelled");    
}
void EmergencyResponseFacade::resolveEmergency(Incident* incident) {

    if (incident == nullptr || console == nullptr)
    {
        return;
    }

    // Active -> Resolved via the State pattern.
    incident->resolve();
}

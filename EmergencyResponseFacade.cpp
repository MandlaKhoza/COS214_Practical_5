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


EmergencyResponseFacade::EmergencyResponseFacade(
    OperatorConsole* console,
    ResponseMediator* coordinator,
    AlertService* alertService
) {
    this->console = console;
    this->coordinator = coordinator;
    this->alertService = alertService;
} 

void EmergencyResponseFacade::declareEmergency(
    Incident* incident,
    AreaComponent* area,
    ResponseComponent* unit
) {

    if (incident == nullptr || area == nullptr || unit == nullptr || console == nullptr || alertService == nullptr)
    {
        return;
    }

    DispatchUnitCommand* dispatch = new DispatchUnitCommand(unit, incident);

    LockAreaCommand* lock = new LockAreaCommand(area);

    IssueAlertCommand* alert = new IssueAlertCommand(alertService, "Emergency reported: " + incident->getDescription(), "HIGH");

    console->executeCommand(dispatch);
    console->executeCommand(lock);
    console->executeCommand(alert);

}

void EmergencyResponseFacade::cancelEmergency(Incident* incident) {
    

    if (incident == nullptr)
    {
        return;
    }

    // Reversing previously executed emergency actions
    console->undoLast();
    console->undoLast();
    console->undoLast();

    incident->cancel();
    
}
#ifndef EMERGENCYRESPONSEFACADE_H
#define EMERGENCYRESPONSEFACADE_H

class OperatorConsole;
class ResponseMediator;
class AlertService;
class Incident;
class AreaComponent;
class ResponseComponent;

/**
 * @class EmergencyResponseFacade
 * @brief Provides a simplified interface for coordinating emergency responses.
 *
 * The EmergencyResponseFacade coordinates multiple CampusGuard subsystems
 * to perform high-level emergency operations. It uses the operator console,
 * response mediator, and alert service to manage the response to an incident.
 */
class EmergencyResponseFacade
{
private:
    OperatorConsole* console;
    ResponseMediator* coordinator;
    AlertService* alertService;

public:

    /**
     * @brief Constructs an EmergencyResponseFacade.
     *
     * @param console The operator console used to execute emergency commands.
     * @param coordinator The mediator responsible for coordinating response components.
     * @param alertService The service responsible for issuing emergency alerts.
     */
    EmergencyResponseFacade(
        OperatorConsole* console,
        ResponseMediator* coordinator,
        AlertService* alertService
    );

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
    void declareEmergency(
        Incident* incident,
        AreaComponent* area,
        ResponseComponent* unit
    );

    /**
     * @brief Cancels an active emergency response.
     *
     * Reverses the previously executed emergency actions and cancels
     * the associated incident.
     *
     * @param incident The incident whose emergency response should be cancelled.
     */
    void cancelEmergency(Incident* incident);
};

#endif
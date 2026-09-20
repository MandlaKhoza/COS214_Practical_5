#ifndef EMERGENCYRESPONSEFACADE_H
#define EMERGENCYRESPONSEFACADE_H

class OperatorConsole;
class ResponseMediator;
class AlertService;
class Incident;
class AreaComponent;
class ResponseComponent;

class EmergencyResponseFacade
{
private:
    OperatorConsole* console;
    ResponseMediator* coordinator;
    AlertService* alertService;

public:
    EmergencyResponseFacade(
        OperatorConsole* console,
        ResponseMediator* coordinator,
        AlertService* alertService
    );

    void declareEmergency(
        Incident* incident,
        AreaComponent* area,
        ResponseComponent* unit
    );

    void cancelEmergency(Incident* incident);
};

#endif
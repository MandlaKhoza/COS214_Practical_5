#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class AreaComponent;
class ResponseMediator;
class IncidentState;

class Incident
{
private:
    std::string id;
    std::string description;
    AreaComponent* location;
    ResponseMediator* mediator;
    IncidentState* currentState;

public:
    Incident(
        std::string id,
        std::string description,
        AreaComponent* location,
        ResponseMediator* mediator
    );

    ~Incident();

    std::string getId();
    std::string getDescription();
    AreaComponent* getLocation();
    std::string getStatusName();

    void setState(IncidentState* state);

    void dispatch();
    void contain();
    void resolve();
    void cancel();

private:
    void notifyMediator(std::string event);
};

#endif
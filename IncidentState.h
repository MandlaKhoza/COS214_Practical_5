#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class Incident;

class IncidentState
{
public:
    virtual void handleDispatch(Incident* incident) = 0;
    virtual void handleContain(Incident* incident) = 0;
    virtual void handleResolve(Incident* incident) = 0;
    virtual void handleCancel(Incident* incident) = 0;

    virtual std::string getName() = 0;

    virtual ~IncidentState();
};

#endif
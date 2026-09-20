#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "IncidentState.h"

class ActiveState : public IncidentState
{
public:
    void handleDispatch(Incident* incident);
    void handleContain(Incident* incident);
    void handleResolve(Incident* incident);
    void handleCancel(Incident* incident);

    std::string getName();

    ~ActiveState();
};

#endif
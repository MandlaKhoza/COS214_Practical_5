#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

#include "IncidentState.h"

class DispatchedState : public IncidentState
{
public:
    void handleDispatch(Incident* incident);
    void handleContain(Incident* incident);
    void handleResolve(Incident* incident);
    void handleCancel(Incident* incident);

    std::string getName();

    ~DispatchedState();
};

#endif
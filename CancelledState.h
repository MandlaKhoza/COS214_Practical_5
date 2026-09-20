#ifndef CANCELLEDSTATE_H
#define CANCELLEDSTATE_H

#include "IncidentState.h"

class CancelledState : public IncidentState
{
public:
    void handleDispatch(Incident* incident);
    void handleContain(Incident* incident);
    void handleResolve(Incident* incident);
    void handleCancel(Incident* incident);

    std::string getName();

    ~CancelledState();
};

#endif
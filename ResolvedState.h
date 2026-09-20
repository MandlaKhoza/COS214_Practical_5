#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState
{
public:
    void handleDispatch(Incident* incident);
    void handleContain(Incident* incident);
    void handleResolve(Incident* incident);
    void handleCancel(Incident* incident);

    std::string getName();

    ~ResolvedState();
};

#endif
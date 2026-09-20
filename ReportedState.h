#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState
{
public:
    void handleDispatch(Incident* incident);
    void handleContain(Incident* incident);
    void handleResolve(Incident* incident);
    void handleCancel(Incident* incident);

    std::string getName();

    ~ReportedState();
};

#endif
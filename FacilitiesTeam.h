#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseComponent.h"

class AreaComponent;

class FacilitiesTeam : public ResponseComponent
{
public:
    FacilitiesTeam(std::string name);

    void activate();
    void standDown();

    void unlockAssignedArea(AreaComponent* area);

    ~FacilitiesTeam();
};

#endif

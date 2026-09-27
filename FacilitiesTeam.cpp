#include "FacilitiesTeam.h"
#include "AreaComponent.h"
#include <iostream>

FacilitiesTeam::FacilitiesTeam(std::string name)
    : ResponseComponent(name)
{
}

FacilitiesTeam::~FacilitiesTeam()
{
}

void FacilitiesTeam::activate()
{
    // FacilitiesTeam is usually the *receiver* of coordination in this
    // design (ResponseCoordinator calls this directly once a field unit
    // reports "dispatched"), rather than the one reporting events, so it
    // does not notify the mediator itself here.
    std::cout << "[FacilitiesTeam] " << name
              << " preparing the affected area (unlocking doors, clearing routes)."
              << std::endl;
}

void FacilitiesTeam::standDown()
{
    std::cout << "[FacilitiesTeam] " << name
              << " securing the area and standing down." << std::endl;
}

void FacilitiesTeam::unlockAssignedArea(AreaComponent* area)
{
    if (area == nullptr) {
        std::cout << "[FacilitiesTeam] " << name
                  << " was asked to unlock a null area - ignoring."
                  << std::endl;
        return;
    }

    std::cout << "[FacilitiesTeam] " << name
              << " unlocking " << area->getName() << "." << std::endl;
    area->unlock();
}

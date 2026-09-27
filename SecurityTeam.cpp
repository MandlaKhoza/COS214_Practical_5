#include "SecurityTeam.h"
#include "ResponseMediator.h"
#include <iostream>

SecurityTeam::SecurityTeam(std::string name)
    : ResponseComponent(name)
{
}

SecurityTeam::~SecurityTeam()
{
}

void SecurityTeam::activate()
{
    std::cout << "[SecurityTeam] " << name
              << " mobilising to the incident location." << std::endl;

    // Report what happened to *this* colleague only. SecurityTeam has no
    // idea FacilitiesTeam exists, and doesn't decide what should happen
    // next - that's the mediator's job.
    if (mediator != nullptr) {
        mediator->notify(this, "dispatched");
    } else {
        std::cout << "[SecurityTeam] " << name
                  << " has no mediator assigned - cannot report dispatch."
                  << std::endl;
    }
}

void SecurityTeam::standDown()
{
    std::cout << "[SecurityTeam] " << name << " standing down." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "standDown");
    } else {
        std::cout << "[SecurityTeam] " << name
                  << " has no mediator assigned - cannot report stand down."
                  << std::endl;
    }
}

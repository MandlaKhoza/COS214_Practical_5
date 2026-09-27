#include "ResponseCoordinator.h"
#include "ResponseComponent.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include <algorithm>
#include <iostream>

ResponseCoordinator::~ResponseCoordinator()
{
    // Aggregation, not composition: the coordinator was handed pointers to
    // response components it does not own (they are shared with Command
    // receivers elsewhere in the system), so it must NOT delete them here.
    // Just let the vector itself go out of scope.
    components.clear();
}

void ResponseCoordinator::registerComponent(ResponseComponent* component)
{
    if (component == nullptr) {
        return;
    }

    // Avoid registering the same colleague twice.
    bool alreadyRegistered = std::find(
        components.begin(), components.end(), component
    ) != components.end();

    if (alreadyRegistered) {
        return;
    }

    components.push_back(component);
    component->setMediator(this);

    std::cout << "[Coordinator] Registered " << component->getName()
              << " as a response colleague." << std::endl;
}

void ResponseCoordinator::notify(ResponseComponent* sender, std::string event)
{
    if (sender == nullptr) {
        std::cout << "[Coordinator] Ignored notification with no sender."
                  << std::endl;
        return;
    }

    std::cout << "[Coordinator] " << sender->getName()
              << " reported event: \"" << event << "\"" << std::endl;

    // This is the core Mediator behaviour: the sender only ever reports
    // what happened to itself. It has no idea which other colleagues
    // exist or what they should do about it - that decision lives here,
    // not in SecurityTeam/MedicalTeam/FacilitiesTeam themselves.

    if (event == "dispatched") {
        // A security or medical unit going active on an incident means
        // the area they are heading into needs to be prepared. Rather
        // than SecurityTeam knowing about FacilitiesTeam directly, it
        // just reports "dispatched" and the coordinator decides that
        // facilities should mobilise too.
        bool isFieldUnit =
            dynamic_cast<SecurityTeam*>(sender) != nullptr ||
            dynamic_cast<MedicalTeam*>(sender) != nullptr;

        if (isFieldUnit) {
            for (ResponseComponent* component : components) {
                FacilitiesTeam* facilities =
                    dynamic_cast<FacilitiesTeam*>(component);

                if (facilities != nullptr && facilities != sender) {
                    std::cout << "[Coordinator] Directing "
                              << facilities->getName()
                              << " to prepare the affected area."
                              << std::endl;
                    facilities->activate();
                }
            }
        }
    }
    else if (event == "standDown") {
        // Symmetric to the above: once a field unit stands down, tell
        // facilities to stand down as well, unless another unit is still
        // active (kept simple here - a fuller implementation could track
        // how many field units are currently active).
        for (ResponseComponent* component : components) {
            FacilitiesTeam* facilities =
                dynamic_cast<FacilitiesTeam*>(component);

            if (facilities != nullptr && facilities != sender) {
                std::cout << "[Coordinator] Releasing "
                          << facilities->getName()
                          << " now that " << sender->getName()
                          << " has stood down." << std::endl;
                facilities->standDown();
            }
        }
    }
    else {
        std::cout << "[Coordinator] No coordinated response defined for \""
                  << event << "\"." << std::endl;
    }
}

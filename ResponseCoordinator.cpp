#include "ResponseCoordinator.h"
#include "ResponseComponent.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Destroys the coordinator.
 *
 * Deliberately does not delete any of the registered ResponseComponent
 * pointers: this is an aggregation relationship, not composition. The
 * coordinator was handed pointers to components it does not own (they
 * are shared with Command receivers elsewhere in the system), so
 * ownership - and therefore deletion - stays with whoever created them.
 * Only the internal vector itself is cleared.
 */
ResponseCoordinator::~ResponseCoordinator()
{
    components.clear();
}

/**
 * @brief Registers a colleague with this mediator.
 *
 * Adds @p component to the set of colleagues this coordinator manages
 * and points its mediator reference back at this coordinator, so the
 * colleague can later call notify() on state changes. Null pointers and
 * components already registered are silently ignored rather than
 * causing duplicate entries or a crash.
 *
 * @param component The response component to register. Ownership is
 *        not taken; the coordinator only stores the pointer.
 */
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

/**
 * @brief Reacts to an event reported by a colleague.
 *
 * This is the heart of the Mediator pattern: @p sender only ever reports
 * what happened to itself (e.g. "dispatched"), and has no knowledge of
 * which other colleagues exist or what should happen next as a result -
 * that decision is made entirely inside this method, not inside
 * SecurityTeam, MedicalTeam or FacilitiesTeam.
 *
 * Currently handled events:
 *  - "dispatched": if the sender is a SecurityTeam or MedicalTeam, every
 *    registered FacilitiesTeam (other than the sender) is directed to
 *    activate() and prepare the affected area.
 *  - "standDown": the symmetric case - every other registered
 *    FacilitiesTeam is told to standDown() as well.
 *  - anything else: reported but explicitly left unhandled, so an
 *    unrecognised event fails safely instead of being silently ignored.
 *
 * @param sender The colleague reporting the event. A null sender is
 *        handled gracefully and simply logged.
 * @param event  A short, case-sensitive string identifying what
 *        happened (e.g. "dispatched", "standDown").
 */
void ResponseCoordinator::notify(ResponseComponent* sender, std::string event)
{
    if (sender == nullptr) {
        std::cout << "[Coordinator] Ignored notification with no sender."
                  << std::endl;
        return;
    }

    std::cout << "[Coordinator] " << sender->getName()
              << " reported event: \"" << event << "\"" << std::endl;

    if (event == "dispatched") {
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

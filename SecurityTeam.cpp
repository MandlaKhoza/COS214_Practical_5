#include "SecurityTeam.h"
#include "ResponseMediator.h"
#include <iostream>

/**
 * @brief Constructs a security team colleague.
 * @param name A human-readable identifier for this team.
 */
SecurityTeam::SecurityTeam(std::string name)
    : ResponseComponent(name)
{
}

/**
 * @brief Destroys the security team. No dynamically-owned members to clean up.
 */
SecurityTeam::~SecurityTeam()
{
}

/**
 * @brief Mobilises this security team to the incident location.
 *
 * Performs its own domain behaviour, then reports the "dispatched" event
 * to its mediator (if one has been assigned via setMediator()). This
 * team has no knowledge of FacilitiesTeam, MedicalTeam or any other
 * colleague - deciding what else should happen as a result of a
 * dispatch is entirely the mediator's responsibility.
 */
void SecurityTeam::activate()
{
    std::cout << "[SecurityTeam] " << name
              << " mobilising to the incident location." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "dispatched");
    } else {
        std::cout << "[SecurityTeam] " << name
                  << " has no mediator assigned - cannot report dispatch."
                  << std::endl;
    }
}

/**
 * @brief Stands this security team down.
 *
 * Symmetric to activate(): performs its own domain behaviour, then
 * reports the "standDown" event to its mediator so any coordinated
 * response (e.g. releasing facilities) can be reversed.
 */
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

#include "MedicalTeam.h"
#include "ResponseMediator.h"
#include <iostream>

/**
 * @brief Constructs a medical team colleague.
 * @param name A human-readable identifier for this team.
 */
MedicalTeam::MedicalTeam(std::string name)
    : ResponseComponent(name)
{
}

/**
 * @brief Destroys the medical team. No dynamically-owned members to clean up.
 */
MedicalTeam::~MedicalTeam()
{
}

/**
 * @brief Dispatches this medical team to the incident location.
 *
 * Performs its own domain behaviour, then reports the "dispatched" event
 * to its mediator (if one has been assigned via setMediator()). Like
 * SecurityTeam, this team has no knowledge of any other colleague -
 * coordinating a response to the dispatch is the mediator's job.
 */
void MedicalTeam::activate()
{
    std::cout << "[MedicalTeam] " << name
              << " responding to the incident location." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "dispatched");
    } else {
        std::cout << "[MedicalTeam] " << name
                  << " has no mediator assigned - cannot report dispatch."
                  << std::endl;
    }
}

/**
 * @brief Stands this medical team down.
 *
 * Symmetric to activate(): performs its own domain behaviour, then
 * reports the "standDown" event to its mediator.
 */
void MedicalTeam::standDown()
{
    std::cout << "[MedicalTeam] " << name << " standing down." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "standDown");
    } else {
        std::cout << "[MedicalTeam] " << name
                  << " has no mediator assigned - cannot report stand down."
                  << std::endl;
    }
}

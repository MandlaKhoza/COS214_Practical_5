#include "FacilitiesTeam.h"
#include "AreaComponent.h"
#include <iostream>

/**
 * @brief Constructs a facilities team colleague.
 * @param name A human-readable identifier for this team.
 */
FacilitiesTeam::FacilitiesTeam(std::string name)
    : ResponseComponent(name)
{
}

/**
 * @brief Destroys the facilities team. No dynamically-owned members to clean up.
 */
FacilitiesTeam::~FacilitiesTeam()
{
}

/**
 * @brief Prepares the affected area in response to mediator coordination.
 *
 * Unlike SecurityTeam and MedicalTeam, FacilitiesTeam is typically the
 * *receiver* of coordination in this design: ResponseCoordinator calls
 * this directly once a field unit reports a "dispatched" event, rather
 * than FacilitiesTeam reporting an event of its own here.
 */
void FacilitiesTeam::activate()
{
    std::cout << "[FacilitiesTeam] " << name
              << " preparing the affected area (unlocking doors, clearing routes)."
              << std::endl;
}

/**
 * @brief Secures the area and stands this facilities team down.
 *
 * Called directly by ResponseCoordinator once a field unit reports a
 * "standDown" event.
 */
void FacilitiesTeam::standDown()
{
    std::cout << "[FacilitiesTeam] " << name
              << " securing the area and standing down." << std::endl;
}

/**
 * @brief Unlocks a specific area on behalf of this facilities team.
 *
 * Delegates the actual unlock operation to @p area, which may be a
 * single Zone or a composite AreaGroup - FacilitiesTeam does not need to
 * know which, since both expose the same AreaComponent interface.
 *
 * @param area The area to unlock. A null pointer is handled gracefully
 *        and logged rather than dereferenced.
 */
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

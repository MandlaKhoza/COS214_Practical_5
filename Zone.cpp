#include "Zone.h"
#include "IAccessControl.h"

/**
 * @brief Constructs a Zone.
 *
 * @param name The name of the zone.
 * @param zoneId The identifier of the zone.
 * @param accessControl The access-control service used by the zone.
 */
Zone::Zone(
    std::string name,
    std::string zoneId,
    IAccessControl* accessControl
)
    : AreaComponent(name),
      zoneId(zoneId),
      locked(false),
      accessControl(accessControl)
{
}

/**
 * @brief Locks the zone.
 *
 * Uses the access-control service to lock the zone.
 */
void Zone::lock()
{
    if (!locked && accessControl != 0)
    {
        accessControl->lockZone(zoneId);
        locked = true;
    }
}

/**
 * @brief Unlocks the zone.
 *
 * Uses the access-control service to unlock the zone.
 */
void Zone::unlock()
{
    if (locked && accessControl != 0)
    {
        accessControl->unlockZone(zoneId);
        locked = false;
    }
}

/**
 * @brief Checks whether the zone is currently locked.
 *
 * @return true if the zone is locked, otherwise false.
 */
bool Zone::isLocked()
{
    return locked;
}

/**
 * @brief Destroys the Zone.
 *
 * The Zone does not own the access-control object,
 * so the access-control object is not deleted here.
 */
Zone::~Zone()
{
}
#include "AccessControlAdapter.h"
#include "LegacyAccessControlSystem.h"
#include <iostream>

/**
 * @brief Constructs an adapter around an existing legacy system.
 *
 * @param legacySystem The legacy/external access-control system to wrap.
 *        Ownership is transferred to this adapter - it will be deleted
 *        in ~AccessControlAdapter().
 */
AccessControlAdapter::AccessControlAdapter(LegacyAccessControlSystem* legacySystem)
    : legacySystem(legacySystem)
{
}

/**
 * @brief Destroys the adapter and its wrapped legacy system.
 *
 * Composition, not aggregation: this adapter exists specifically to wrap
 * the legacy system, and nothing else in CampusGuard holds a pointer to
 * it, so the adapter is responsible for its lifetime.
 */
AccessControlAdapter::~AccessControlAdapter()
{
    delete legacySystem;
}

/**
 * @brief Locks the given zone via the wrapped legacy system.
 *
 * Translates CampusGuard's expected interface (lockZone) into the legacy
 * system's actual method name and semantics (engageLockdown). Nothing
 * outside this adapter ever needs to know that mismatch exists.
 *
 * @param zoneId Identifier of the zone to lock.
 */
void AccessControlAdapter::lockZone(std::string zoneId)
{
    std::cout << "[AccessControlAdapter] lockZone(\"" << zoneId
              << "\") -> engageLockdown(\"" << zoneId << "\")" << std::endl;
    legacySystem->engageLockdown(zoneId);
}

/**
 * @brief Unlocks the given zone via the wrapped legacy system.
 *
 * Translates unlockZone into the legacy system's releaseLockdown.
 *
 * @param zoneId Identifier of the zone to unlock.
 */
void AccessControlAdapter::unlockZone(std::string zoneId)
{
    std::cout << "[AccessControlAdapter] unlockZone(\"" << zoneId
              << "\") -> releaseLockdown(\"" << zoneId << "\")" << std::endl;
    legacySystem->releaseLockdown(zoneId);
}

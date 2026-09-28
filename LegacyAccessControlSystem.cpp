#include "LegacyAccessControlSystem.h"
#include <iostream>

/**
 * @brief Engages a physical lockdown for the given zone code.
 *
 * Represents the legacy system's own, pre-existing interface - note the
 * naming ("engage"/"zoneCode") deliberately does not match the
 * lockZone/zoneId naming CampusGuard wants, which is exactly what
 * AccessControlAdapter exists to translate.
 *
 * @param zoneCode Legacy-system identifier for the zone to lock down.
 */
void LegacyAccessControlSystem::engageLockdown(std::string zoneCode)
{
    std::cout << "[LegacySystem] ENGAGE_LOCKDOWN signal sent for zone code "
              << zoneCode << std::endl;
}

/**
 * @brief Releases a physical lockdown for the given zone code.
 * @param zoneCode Legacy-system identifier for the zone to unlock.
 */
void LegacyAccessControlSystem::releaseLockdown(std::string zoneCode)
{
    std::cout << "[LegacySystem] RELEASE_LOCKDOWN signal sent for zone code "
              << zoneCode << std::endl;
}

/**
 * @brief Reports the legacy system's own status.
 *
 * Exposed only on LegacyAccessControlSystem itself (not part of
 * IAccessControl), to show that the adaptee's original interface remains
 * independently usable outside of the adapter if something needs it
 * directly.
 *
 * @return A short status string.
 */
std::string LegacyAccessControlSystem::getSystemStatus()
{
    return "LEGACY_SYSTEM_ONLINE";
}

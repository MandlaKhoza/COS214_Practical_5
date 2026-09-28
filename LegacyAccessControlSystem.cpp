#include "LegacyAccessControlSystem.h"
#include <iostream>

// NOTE: your header package only included LegacyAccessControlSystem.h,
// not a .cpp. This is a plausible stand-in for "the legacy/external
// system CampusGuard has to integrate with" - simulating a system that
// exposes engageLockdown/releaseLockdown instead of the lockZone/
// unlockZone interface CampusGuard actually wants (that mismatch is
// exactly what AccessControlAdapter exists to solve). If your team
// already has a real implementation for this, use that instead - only
// the .h's method signatures matter to the Adapter.

void LegacyAccessControlSystem::engageLockdown(std::string zoneCode)
{
    std::cout << "[LegacySystem] ENGAGE_LOCKDOWN signal sent for zone code "
              << zoneCode << std::endl;
}

void LegacyAccessControlSystem::releaseLockdown(std::string zoneCode)
{
    std::cout << "[LegacySystem] RELEASE_LOCKDOWN signal sent for zone code "
              << zoneCode << std::endl;
}

std::string LegacyAccessControlSystem::getSystemStatus()
{
    return "LEGACY_SYSTEM_ONLINE";
}

#include "AccessControlAdapter.h"
#include "LegacyAccessControlSystem.h"
#include <iostream>

AccessControlAdapter::AccessControlAdapter(LegacyAccessControlSystem* legacySystem)
    : legacySystem(legacySystem)
{
}

AccessControlAdapter::~AccessControlAdapter()
{
    // Composition: this adapter exists specifically to wrap the legacy
    // system, and nothing else in CampusGuard holds a pointer to it, so
    // the adapter is responsible for its lifetime.
    delete legacySystem;
}

void AccessControlAdapter::lockZone(std::string zoneId)
{
    // Translate CampusGuard's expected interface (lockZone) into the
    // legacy system's actual method name and semantics (engageLockdown).
    // Nothing outside the adapter ever needs to know that mismatch exists.
    std::cout << "[AccessControlAdapter] lockZone(\"" << zoneId
              << "\") -> engageLockdown(\"" << zoneId << "\")" << std::endl;
    legacySystem->engageLockdown(zoneId);
}

void AccessControlAdapter::unlockZone(std::string zoneId)
{
    std::cout << "[AccessControlAdapter] unlockZone(\"" << zoneId
              << "\") -> releaseLockdown(\"" << zoneId << "\")" << std::endl;
    legacySystem->releaseLockdown(zoneId);
}

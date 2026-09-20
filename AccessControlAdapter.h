#ifndef ACCESSCONTROLADAPTER_H
#define ACCESSCONTROLADAPTER_H

#include "IAccessControl.h"

class LegacyAccessControlSystem;

class AccessControlAdapter : public IAccessControl
{
private:
    LegacyAccessControlSystem* legacySystem;

public:
    AccessControlAdapter(
        LegacyAccessControlSystem* legacySystem
    );

    ~AccessControlAdapter();

    void lockZone(std::string zoneId);
    void unlockZone(std::string zoneId);
};

#endif
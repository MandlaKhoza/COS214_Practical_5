#ifndef ZONE_H
#define ZONE_H

#include "AreaComponent.h"

class IAccessControl;

class Zone : public AreaComponent
{
private:
    std::string zoneId;
    bool locked;
    IAccessControl* accessControl;

public:
    Zone(
        std::string name,
        std::string zoneId,
        IAccessControl* accessControl
    );

    void lock();
    void unlock();
    bool isLocked();

    ~Zone();
};

#endif
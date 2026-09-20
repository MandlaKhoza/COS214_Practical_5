#ifndef IACCESSCONTROL_H
#define IACCESSCONTROL_H

#include <string>

class IAccessControl
{
public:
    virtual void lockZone(std::string zoneId) = 0;
    virtual void unlockZone(std::string zoneId) = 0;

    virtual ~IAccessControl();
};

#endif
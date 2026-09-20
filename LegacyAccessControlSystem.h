#ifndef LEGACYACCESSCONTROLSYSTEM_H
#define LEGACYACCESSCONTROLSYSTEM_H

#include <string>

class LegacyAccessControlSystem
{
public:
    void engageLockdown(std::string zoneCode);
    void releaseLockdown(std::string zoneCode);
    std::string getSystemStatus();
};

#endif
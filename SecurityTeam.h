#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseComponent.h"

class SecurityTeam : public ResponseComponent
{
public:
    SecurityTeam(std::string name);
    void activate();
    void standDown();

    ~SecurityTeam();
};

#endif
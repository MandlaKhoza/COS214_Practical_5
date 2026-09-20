#ifndef RESPONSECOORDINATOR_H
#define RESPONSECOORDINATOR_H

#include "ResponseMediator.h"
#include <vector>

class ResponseComponent;

class ResponseCoordinator : public ResponseMediator
{
private:
    std::vector<ResponseComponent*> components;

public:
    ~ResponseCoordinator();

    void notify(
        ResponseComponent* sender,
        std::string event
    );

    void registerComponent(
        ResponseComponent* component
    );
};

#endif
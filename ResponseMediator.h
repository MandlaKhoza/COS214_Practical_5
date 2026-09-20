#ifndef RESPONSEMEDIATOR_H
#define RESPONSEMEDIATOR_H
#include <string>
class ResponseComponent;

class ResponseMediator
{
public:
    virtual void notify(
        ResponseComponent* sender,
        std::string event
    ) = 0;

    virtual void registerComponent(
        ResponseComponent* component
    ) = 0;

    virtual ~ResponseMediator();
};

#endif
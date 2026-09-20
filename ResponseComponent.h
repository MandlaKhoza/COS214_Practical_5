#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>

class ResponseMediator;

class ResponseComponent
{
protected:
    ResponseMediator* mediator;
    std::string name;

public:
    ResponseComponent(std::string name);

    virtual ~ResponseComponent();

    void setMediator(ResponseMediator* mediator);
    std::string getName();

    virtual void activate();
    virtual void standDown();
};

#endif
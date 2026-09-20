#ifndef AREACOMPONENT_H
#define AREACOMPONENT_H

#include <string>

class AreaComponent
{
protected:
    std::string name;

public:
    AreaComponent(std::string name);

    virtual ~AreaComponent();

    virtual std::string getName();

    virtual void lock();
    virtual void unlock();
    virtual bool isLocked();

    virtual void add(AreaComponent* child);
    virtual void remove(AreaComponent* child);
};

#endif
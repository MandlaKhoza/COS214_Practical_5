#ifndef AREAGROUP_H
#define AREAGROUP_H

#include "AreaComponent.h"
#include <vector>

class AreaGroup : public AreaComponent
{
private:
    std::vector<AreaComponent*> children;

public:
    AreaGroup(std::string name);

    ~AreaGroup();

    void lock();
    void unlock();
    bool isLocked();

    void add(AreaComponent* child);
    void remove(AreaComponent* child);
};

#endif
#include "LockAreaCommand.h"

LockAreaCommand::LockAreaCommand(AreaComponent* area) {
    this->area = area;   
}

void LockAreaCommand::execute() {
    if (area != nullptr)
    {
        area->lock();
    }
    
}

void LockAreaCommand::undo() {
    if (area != nullptr)
    {
        area->unlock();
    }
}
std::string LockAreaCommand::getDescription() const {
    if (area == nullptr) {
        return "Lock area command: no area";
    }

    return area->getName() + " is " + (area->isLocked()?"Locked":"Unlocked");
}

LockAreaCommand::~LockAreaCommand() {}
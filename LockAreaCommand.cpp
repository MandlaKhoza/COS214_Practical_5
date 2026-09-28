#include "LockAreaCommand.h"
/**
 * @brief Creates a command for locking an area.
 * @param area The area to be locked.
 */
LockAreaCommand::LockAreaCommand(AreaComponent* area) {
    this->area = area;   
}
/**
 * @brief Locks the associated area.
 */
void LockAreaCommand::execute() {
    if (area != nullptr)
    {
        area->lock();
    }
    
}
/**
 * @brief Reverses the command by unlocking the associated area.
 */
void LockAreaCommand::undo() {
    if (area != nullptr)
    {
        area->unlock();
    }
}
/**
 * @brief Returns a description of the area's locking status.
 * @return A string describing the area and its lock status.
 */
std::string LockAreaCommand::getDescription() const {
    if (area == nullptr) {
        return "Lock area command: no area";
    }

    return area->getName() + " is " + (area->isLocked()?"Locked":"Unlocked");
}
/**
 * @brief Destroys the lock area command.
 */
LockAreaCommand::~LockAreaCommand() {}

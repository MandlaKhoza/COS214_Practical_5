#ifndef LOCKAREACOMMAND_H
#define LOCKAREACOMMAND_H

#include "Command.h"
#include "AreaComponent.h"

class AreaComponent;

/**
 * @class LockAreaCommand
 * @brief Command responsible for locking a campus area.
 *
 * Uses an AreaComponent as its receiver. The command can also be undone
 * to unlock the affected area.
 */
class LockAreaCommand : public Command
{
private:
    AreaComponent* area;

public:
    /**
     * @brief Creates a command for locking an area.
     * @param area The area to be locked.
     */
    LockAreaCommand(AreaComponent* area);

    /**
     * @brief Locks the associated area.
     */
    void execute() override;

    /**
     * @brief Reverses the command by unlocking the associated area.
     */
    void undo() override;

    /**
     * @brief Returns a description of the area's locking status.
     * @return A string describing the area and its lock status.
     */
    std::string getDescription() const override;

    /**
     * @brief Destroys the lock area command.
     */
    ~LockAreaCommand();
};

#endif
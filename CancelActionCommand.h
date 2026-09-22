#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include <string>

/**
 * @class CancelActionCommand
 * @brief Command responsible for cancelling another command.
 *
 * Stores a target Command and cancels its action by invoking its undo
 * operation. The cancellation itself can also be reversed.
 */
class CancelActionCommand : public Command
{
private:
    Command* target;

public:

    /**
     * @brief Creates a command that cancels another command.
     * @param target The command whose action should be cancelled.
     */
    CancelActionCommand(Command* target);

    /**
     * @brief Cancels the target command by undoing it.
     */
    void execute() override;

    /**
     * @brief Reverses the cancellation by executing the target command again.
     */
    void undo() override;

    /**
     * @brief Returns a description of the cancellation command.
     * @return A string describing the command being cancelled.
     */
    std::string getDescription() const override;

    /**
     * @brief Destroys the cancel action command.
     */
    ~CancelActionCommand();
};

#endif
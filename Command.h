#ifndef COMMAND_H
#define COMMAND_H

#include <string>

/**
 * @class Command
 * @brief Defines the interface for all executable CampusGuard commands.
 *
 * Provides operations for executing, undoing, and describing a command.
 * Concrete commands implement this interface to perform specific actions.
 */
class Command {
public:
    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     */
    virtual ~Command() = default;

    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

     /**
     * @brief Reverses the effects of the command.
     */
    virtual void undo() = 0;

    /**
     * @brief Returns a description of the command.
     * @return A string describing the command.
     */
    virtual std::string getDescription() const = 0;
};

#endif
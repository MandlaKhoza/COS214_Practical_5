#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include <vector>
#include <iostream>

#include "Command.h"

class Command;

/**
 * @class OperatorConsole
 * @brief Invoker responsible for executing and managing CampusGuard commands.
 *
 * Executes Command objects and maintains a history of executed commands,
 * allowing previous actions to be inspected or undone.
 */
class OperatorConsole
{
private:
    std::vector<Command*> history;

public:

    /**
     * @brief Destroys the operator console.
     */
    ~OperatorConsole();

    /**
     * @brief Executes a command and stores it in the command history.
     * @param cmd The command to execute.
     */
    void executeCommand(Command* cmd);

    /**
     * @brief Undoes the most recently executed command.
     *
     * Does nothing if the command history is empty.
     */
    void undoLast();

    /**
     * @brief Prints descriptions of the commands currently stored in history.
     */
    void printHistory();
};

#endif
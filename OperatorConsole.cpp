#include "OperatorConsole.h"
/**
 * @brief Executes a command and stores it in the command history.
 * @param cmd The command to execute.
 */
void OperatorConsole::executeCommand(Command* cmd) {
    if (cmd != nullptr)
    {
        cmd->execute();
        history.push_back(cmd); 
    }
    
}
/**
 * @brief Undoes the most recently executed command.
 *
 * Does nothing if the command history is empty.
 */
void OperatorConsole::undoLast() {
    if (!history.empty())
    {
        Command* lastCommand = history.back();
        lastCommand->undo();
        history.pop_back();

        delete lastCommand;
        
    }
}
/**
 * @brief Prints descriptions of the commands currently stored in history.
 */
void OperatorConsole::printHistory() {
    if (!history.empty())
    {
        for(Command* commands : history) {
            std::cout << commands->getDescription() << std::endl;
        }
    }
}
/**
 * @brief Destroys the operator console.
 */
OperatorConsole::~OperatorConsole() {
    for (Command* command : history)
    {
        delete command;
    }

    history.clear();
    
}

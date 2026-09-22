#include "OperatorConsole.h"

void OperatorConsole::executeCommand(Command* cmd) {
    if (cmd != nullptr)
    {
        cmd->execute();
        history.push_back(cmd); 
    }
    
}

void OperatorConsole::undoLast() {
    if (!history.empty())
    {
        Command* lastCommand = history.back();
        lastCommand->undo();
        history.pop_back();
        
    }
}

void OperatorConsole::printHistory() {
    if (!history.empty())
    {
        for(Command* commands : history) {
            std::cout << commands->getDescription() << std::endl;
        }
    }
}

OperatorConsole::~OperatorConsole() {}

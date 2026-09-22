#include "CancelActionCommand.h"

CancelActionCommand::CancelActionCommand(Command* target) {
    this->target = target;
}

void CancelActionCommand::execute() {
    if (target != nullptr)
    {
        target->execute();
        
    }
    
}
void CancelActionCommand::undo() {
    if (target != nullptr)
    {
        target->undo();
        
    }
    
}
std::string CancelActionCommand::getDescription() const {
   return "Cancel" + target->getDescription();
}

CancelActionCommand::~CancelActionCommand() {}
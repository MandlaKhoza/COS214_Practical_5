#include "CancelActionCommand.h"

CancelActionCommand::CancelActionCommand(Incident* incident) {
    this->incident = incident;
}

// Cancels the associated incident.
void CancelActionCommand::execute() {
    if (incident != nullptr)
    {
        incident->cancel();
        
    }
    
}

// Restores the cancelled incident to its dispatched state.
void CancelActionCommand::undo() {
    if (incident != nullptr)
    {
        incident->dispatch();
        
    }
    
}
std::string CancelActionCommand::getDescription() const {
    if (incident == nullptr) {
        return "Cancel: no incident";
    }

    return "Canceled: " + incident->getDescription();
}

CancelActionCommand::~CancelActionCommand() {}
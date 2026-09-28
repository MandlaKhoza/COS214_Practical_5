#include "CancelActionCommand.h"
#include "DispatchedState.h"
/**
 * @brief Creates a command for cancelling an incident.
 * @param incident The incident that should be cancelled.
 */
CancelActionCommand::CancelActionCommand(Incident* incident) {
    this->incident = incident;
}

/**
* @brief Cancels the associated incident.
*/
// Cancels the associated incident.
void CancelActionCommand::execute() {
    if (incident != nullptr)
    {
        incident->cancel();
        
    }
    
}
/**
* @brief Reverses the cancellation of the incident.
*/
// Restores the cancelled incident to its dispatched state.
void CancelActionCommand::undo() {
    if (incident != nullptr)
    {
        incident->dispatch();
        
    }
    
}
/**
* @brief Returns a description of the cancellation command.
* @return A string describing the incident being cancelled.
*/
std::string CancelActionCommand::getDescription() const {
    if (incident == nullptr) {
        return "Cancel: no incident";
    }

    return "Canceled: " + incident->getDescription();
}
    /**
     * @brief Destroys the cancel action command.
     */
CancelActionCommand::~CancelActionCommand() {}

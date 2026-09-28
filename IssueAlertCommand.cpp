#include "IssueAlertCommand.h"

IssueAlertCommand::IssueAlertCommand(AlertService* alertService, std::string message, std::string priority
) {
    this->alertService = alertService;
    this->message = message;
    this->priority = priority;
}

void IssueAlertCommand::execute() {
    if (alertService != nullptr)
    {
        alertService->sendAlert(message, priority);
    }
}

void IssueAlertCommand::undo() {
    if (alertService != nullptr)
    {
        alertService->retractAlert(message);
    }
    
}

std::string IssueAlertCommand::getDescription() const {
    return "Alert: " + message + " | Priority: " + priority;

}

IssueAlertCommand::~IssueAlertCommand() {}
#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"

class AlertService;

class IssueAlertCommand : public Command
{
private:
    AlertService* alertService;
    std::string message;
    std::string priority;

public:
    IssueAlertCommand(
        AlertService* alertService,
        std::string message,
        std::string priority
    );

    void execute();
    void undo();
    std::string getDescription();

    ~IssueAlertCommand();
};

#endif
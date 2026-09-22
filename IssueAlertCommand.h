#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "AlertService.h"

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

    void execute() override;
    void undo() override;
    std::string getDescription() const override;

    ~IssueAlertCommand();
};

#endif
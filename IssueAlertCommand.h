#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "AlertService.h"

class AlertService;

/**
 * @class IssueAlertCommand
 * @brief Command responsible for issuing an emergency alert.
 *
 * Uses an AlertService to send an alert containing a message and priority.
 * The command can be undone by retracting the alert.
 */
class IssueAlertCommand : public Command
{
private:
    AlertService* alertService;
    std::string message;
    std::string priority;

public:

    /**
     * @brief Creates a command for issuing an emergency alert.
     * @param alertService The service responsible for sending the alert.
     * @param message The message to be sent.
     * @param priority The priority level of the alert.
     */
    IssueAlertCommand(
        AlertService* alertService,
        std::string message,
        std::string priority
    );

    /**
     * @brief Sends the emergency alert.
     */
    void execute() override;

    /**
     * @brief Reverses the command by retracting the alert.
     */
    void undo() override;

    /**
     * @brief Returns a description of the alert command.
     * @return A string containing the alert message and priority.
     */
    std::string getDescription() const override;

    /**
     * @brief Destroys the issue alert command.
     */
    ~IssueAlertCommand();
};

#endif
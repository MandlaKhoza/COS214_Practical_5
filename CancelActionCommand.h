#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include "Incident.h"
#include <string>

/**
 * @class CancelActionCommand
 * @brief Command responsible for cancelling an incident.
 *
 * Represents an explicit cancellation of an incident, such as when
 * an emergency is determined to be a false alarm.
 */
class CancelActionCommand : public Command
{
private:
Incident* incident;

public:

    /**
     * @brief Creates a command for cancelling an incident.
     * @param incident The incident that should be cancelled.
     */
    CancelActionCommand(Incident* incident);

    /**
     * @brief Cancels the associated incident.
     */
    void execute() override;

    /**
     * @brief Reverses the cancellation of the incident.
     */
    void undo() override;

    /**
     * @brief Returns a description of the cancellation command.
     * @return A string describing the incident being cancelled.
     */
    std::string getDescription() const override;

    /**
     * @brief Destroys the cancel action command.
     */
    ~CancelActionCommand();
};

#endif
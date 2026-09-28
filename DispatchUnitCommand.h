#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "ResponseComponent.h"
#include "Incident.h"
#include <string>

class ResponseComponent;
class Incident;

/**
 * @class DispatchUnitCommand
 * @brief Command responsible for dispatching a response unit to an incident.
 *
 * Uses a ResponseComponent as its receiver and associates the response
 * unit with a specific Incident.
 */
class DispatchUnitCommand : public Command
{
private:
    ResponseComponent* unit;
    Incident* incident;

public:
/**
 * @brief Creates a command for dispatching a response unit to an incident.
 * @param unit The response component that will be dispatched.
 * @param incident The incident the unit will respond to.
 */
    DispatchUnitCommand(
        ResponseComponent* unit,
        Incident* incident
    );

    /**
     * @brief Dispatches the response unit and updates the incident.
     */
    void execute() override;

    /**
     * @brief Reverses the dispatch by standing down the response unit.
     */
    void undo() override;

    /**
     * @brief Returns a description of the dispatch command.
     * @return A string describing the unit and incident involved.
     */
    std::string getDescription() const override;

    /**
     * @brief Destroys the dispatch unit command.
     */
    ~DispatchUnitCommand();
};

#endif
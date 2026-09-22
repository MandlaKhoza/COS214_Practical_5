#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "ResponseComponent.h"
#include "Incident.h"
#include <string>

class ResponseComponent;
class Incident;

class DispatchUnitCommand : public Command
{
private:
    ResponseComponent* unit;
    Incident* incident;

public:
    DispatchUnitCommand(
        ResponseComponent* unit,
        Incident* incident
    );

    void execute() override;
    void undo() override;
    std::string getDescription() const override;

    ~DispatchUnitCommand();
};

#endif
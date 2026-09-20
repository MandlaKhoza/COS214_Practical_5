#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"

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

    void execute();
    void undo();
    std::string getDescription();

    ~DispatchUnitCommand();
};

#endif
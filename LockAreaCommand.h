#ifndef LOCKAREACOMMAND_H
#define LOCKAREACOMMAND_H

#include "Command.h"
#include "AreaComponent.h"

class AreaComponent;
class LockAreaCommand : public Command
{
private:
    AreaComponent* area;

public:
    LockAreaCommand(AreaComponent* area);

    void execute() override;
    void undo() override;
    std::string getDescription() const override;

    ~LockAreaCommand();
};

#endif
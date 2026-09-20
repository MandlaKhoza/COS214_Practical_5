#ifndef LOCKAREACOMMAND_H
#define LOCKAREACOMMAND_H

#include "Command.h"

class AreaComponent;

class LockAreaCommand : public Command
{
private:
    AreaComponent* area;

public:
    LockAreaCommand(AreaComponent* area);

    void execute();
    void undo();
    std::string getDescription();

    ~LockAreaCommand();
};

#endif
#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"

class CancelActionCommand : public Command
{
private:
    Command* target;

public:
    CancelActionCommand(Command* target);

    void execute();
    void undo();
    std::string getDescription();

    ~CancelActionCommand();
};

#endif
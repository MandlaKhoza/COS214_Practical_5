#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include <string>


class CancelActionCommand : public Command
{
private:
    Command* target;

public:
    CancelActionCommand(Command* target);

    void execute() override;
    void undo() override;
    std::string getDescription() const override;

    ~CancelActionCommand();
};

#endif
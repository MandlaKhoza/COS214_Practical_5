#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include <vector>

class Command;

class OperatorConsole
{
private:
    std::vector<Command*> history;

public:
    ~OperatorConsole();

    void executeCommand(Command* cmd);
    void undoLast();
    void printHistory();
};

#endif
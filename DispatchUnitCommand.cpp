#include "DispatchUnitCommand.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseComponent* unit, Incident* incident) {
    this->unit = unit;
    this->incident = incident;
}

void DispatchUnitCommand::execute() {
    unit->activate();
    incident->dispatch();
}

void DispatchUnitCommand::undo() {
    unit->standDown();
    //incident->cancel();
}

std::string DispatchUnitCommand::getDescription() const {
    return "Dispatch: " + unit->getName() + ", to incident: " + incident->getDescription();
}

DispatchUnitCommand::~DispatchUnitCommand() {}
#include "MedicalTeam.h"
#include "ResponseMediator.h"
#include <iostream>

MedicalTeam::MedicalTeam(std::string name)
    : ResponseComponent(name)
{
}

MedicalTeam::~MedicalTeam()
{
}

void MedicalTeam::activate()
{
    std::cout << "[MedicalTeam] " << name
              << " responding to the incident location." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "dispatched");
    } else {
        std::cout << "[MedicalTeam] " << name
                  << " has no mediator assigned - cannot report dispatch."
                  << std::endl;
    }
}

void MedicalTeam::standDown()
{
    std::cout << "[MedicalTeam] " << name << " standing down." << std::endl;

    if (mediator != nullptr) {
        mediator->notify(this, "standDown");
    } else {
        std::cout << "[MedicalTeam] " << name
                  << " has no mediator assigned - cannot report stand down."
                  << std::endl;
    }
}

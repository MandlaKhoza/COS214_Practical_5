#include "ResponseComponent.h"
#include <iostream>

ResponseComponent::ResponseComponent(std::string name)
    : mediator(nullptr), name(name)
{
}

ResponseComponent::~ResponseComponent()
{
    // No dynamically-owned members here: mediator is an aggregated
    // reference (this component does not own the coordinator), so it is
    // never deleted from this destructor.
}

void ResponseComponent::setMediator(ResponseMediator* mediator)
{
    this->mediator = mediator;
}

std::string ResponseComponent::getName()
{
    return name;
}

void ResponseComponent::activate()
{
    // Fallback body only - every concrete colleague (SecurityTeam,
    // MedicalTeam, FacilitiesTeam) overrides this with real behaviour
    // and its own mediator notification. This exists purely so the
    // base class is well-formed and not left with an undefined symbol.
    std::cout << "[ResponseComponent] " << name
              << " activated (no specialised behaviour defined)." << std::endl;
}

void ResponseComponent::standDown()
{
    std::cout << "[ResponseComponent] " << name
              << " stood down (no specialised behaviour defined)." << std::endl;
}

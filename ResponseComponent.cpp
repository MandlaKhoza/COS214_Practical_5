#include "ResponseComponent.h"
#include <iostream>

/**
 * @brief Constructs a response component.
 *
 * The component starts with no mediator assigned; it must be registered
 * with a ResponseMediator (e.g. via ResponseCoordinator::registerComponent)
 * before it is able to report events.
 *
 * @param name A human-readable identifier for this component, used in
 *        log output and by the mediator when directing other colleagues.
 */
ResponseComponent::ResponseComponent(std::string name)
    : mediator(nullptr), name(name)
{
}

/**
 * @brief Destroys the response component.
 *
 * No dynamically-owned members exist here: mediator is an aggregated
 * reference (this component does not own the mediator/coordinator it
 * points to), so it is never deleted from this destructor.
 */
ResponseComponent::~ResponseComponent()
{
}

/**
 * @brief Assigns the mediator this component will report events to.
 *
 * @param mediator The mediator to register with. The component does not
 *        take ownership of it.
 */
void ResponseComponent::setMediator(ResponseMediator* mediator)
{
    this->mediator = mediator;
}

/**
 * @brief Returns this component's human-readable name.
 * @return The component's name, as given to the constructor.
 */
std::string ResponseComponent::getName()
{
    return name;
}

/**
 * @brief Default activation behaviour.
 *
 * This fallback body only runs if a concrete colleague chooses not to
 * override activate(). Every concrete colleague currently in the system
 * (SecurityTeam, MedicalTeam, FacilitiesTeam) overrides this with real
 * domain behaviour and its own mediator notification; this exists purely
 * so the base class is well-formed rather than left with an undefined
 * virtual function.
 */
void ResponseComponent::activate()
{
    std::cout << "[ResponseComponent] " << name
              << " activated (no specialised behaviour defined)." << std::endl;
}

/**
 * @brief Default stand-down behaviour.
 *
 * See activate() - this is the equivalent fallback for standDown().
 */
void ResponseComponent::standDown()
{
    std::cout << "[ResponseComponent] " << name
              << " stood down (no specialised behaviour defined)." << std::endl;
}

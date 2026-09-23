#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "ResponseMediator.h"

/**
 * @brief Constructs an Incident.
 *
 * A new incident starts in the Reported state.
 *
 * @param id The unique identifier of the incident.
 * @param description A description of the incident.
 * @param location The area where the incident occurred.
 * @param mediator The mediator responsible for coordinating the incident.
 */
Incident::Incident(
    std::string id,
    std::string description,
    AreaComponent* location,
    ResponseMediator* mediator
)
    : id(id),
      description(description),
      location(location),
      mediator(mediator),
      currentState(new ReportedState())
{
}

/**
 * @brief Destroys the Incident.
 *
 * The Incident owns its current state, so the state is deleted here.
 * The location and mediator are not owned by the Incident.
 */
Incident::~Incident()
{
    delete currentState;
}

/**
 * @brief Gets the incident ID.
 *
 * @return The ID of the incident.
 */
std::string Incident::getId()
{
    return id;
}

/**
 * @brief Gets the incident description.
 *
 * @return The description of the incident.
 */
std::string Incident::getDescription()
{
    return description;
}

/**
 * @brief Gets the location of the incident.
 *
 * @return A pointer to the incident's location.
 */
AreaComponent* Incident::getLocation()
{
    return location;
}

/**
 * @brief Gets the name of the current incident state.
 *
 * @return The current state name.
 */
std::string Incident::getStatusName()
{
    if (currentState != 0)
    {
        return currentState->getName();
    }

    return "Unknown";
}

/**
 * @brief Changes the current state of the incident.
 *
 * The Incident owns the current state, so the previous state
 * is deleted before the new state is assigned.
 *
 * @param state The new state of the incident.
 */
void Incident::setState(IncidentState* state)
{
    if (state == 0)
    {
        return;
    }

    delete currentState;
    currentState = state;

    notifyMediator(currentState->getName());
}

/**
 * @brief Dispatches the incident.
 *
 * The request is passed to the current state so that the
 * State pattern determines the appropriate behaviour.
 */
void Incident::dispatch()
{
    if (currentState != 0)
    {
        currentState->handleDispatch(this);
    }
}

/**
 * @brief Contains the incident.
 *
 * The request is passed to the current state so that the
 * State pattern determines the appropriate behaviour.
 */
void Incident::contain()
{
    if (currentState != 0)
    {
        currentState->handleContain(this);
    }
}

/**
 * @brief Resolves the incident.
 *
 * The request is passed to the current state so that the
 * State pattern determines the appropriate behaviour.
 */
void Incident::resolve()
{
    if (currentState != 0)
    {
        currentState->handleResolve(this);
    }
}

/**
 * @brief Cancels the incident.
 *
 * The request is passed to the current state so that the
 * State pattern determines the appropriate behaviour.
 */
void Incident::cancel()
{
    if (currentState != 0)
    {
        currentState->handleCancel(this);
    }
}

/**
 * @brief Notifies the mediator about an incident event.
 *
 * The current ResponseMediator interface accepts ResponseComponent
 * objects as senders, so Incident does not directly send the event
 * through this interface.
 *
 * @param event The event associated with the incident.
 */
void Incident::notifyMediator(std::string event)
{
    (void)event;
}
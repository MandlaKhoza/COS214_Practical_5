#include "DispatchedState.h"
#include "Incident.h"

/**
 * @brief Handles a dispatch request while the incident is dispatched.
 *
 * The incident is already in the dispatched state,
 * so no state transition occurs.
 *
 * @param incident The incident being handled.
 */
void DispatchedState::handleDispatch(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a contain request while the incident is dispatched.
 *
 * The incident can proceed to the Active state.
 *
 * @param incident The incident being handled.
 */
void DispatchedState::handleContain(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a resolve request while the incident is dispatched.
 *
 * The incident must first become active before it can be resolved.
 *
 * @param incident The incident being handled.
 */
void DispatchedState::handleResolve(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a cancel request while the incident is dispatched.
 *
 * @param incident The incident being handled.
 */
void DispatchedState::handleCancel(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Gets the name of the current state.
 *
 * @return The name of the state.
 */
std::string DispatchedState::getName()
{
    return "Dispatched";
}

/**
 * @brief Destroys the DispatchedState object.
 */
DispatchedState::~DispatchedState()
{
}
#include "ResolvedState.h"
#include "Incident.h"

/**
 * @brief Handles a dispatch request for a resolved incident.
 *
 * A resolved incident cannot be dispatched again.
 *
 * @param incident The incident being handled.
 */
void ResolvedState::handleDispatch(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a contain request for a resolved incident.
 *
 * A resolved incident does not require containment.
 *
 * @param incident The incident being handled.
 */
void ResolvedState::handleContain(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a resolve request for a resolved incident.
 *
 * The incident is already resolved.
 *
 * @param incident The incident being handled.
 */
void ResolvedState::handleResolve(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a cancel request for a resolved incident.
 *
 * A resolved incident cannot be cancelled.
 *
 * @param incident The incident being handled.
 */
void ResolvedState::handleCancel(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Gets the name of the current state.
 *
 * @return The name of the state.
 */
std::string ResolvedState::getName()
{
    return "Resolved";
}

/**
 * @brief Destroys the ResolvedState object.
 */
ResolvedState::~ResolvedState()
{
}
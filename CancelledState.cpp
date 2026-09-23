#include "CancelledState.h"
#include "Incident.h"

/**
 * @brief Handles a dispatch request for a cancelled incident.
 *
 * A cancelled incident cannot be dispatched again.
 *
 * @param incident The incident being handled.
 */
void CancelledState::handleDispatch(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a contain request for a cancelled incident.
 *
 * A cancelled incident does not require containment.
 *
 * @param incident The incident being handled.
 */
void CancelledState::handleContain(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a resolve request for a cancelled incident.
 *
 * A cancelled incident cannot be resolved.
 *
 * @param incident The incident being handled.
 */
void CancelledState::handleResolve(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a cancel request for a cancelled incident.
 *
 * The incident is already cancelled.
 *
 * @param incident The incident being handled.
 */
void CancelledState::handleCancel(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Gets the name of the current state.
 *
 * @return The name of the state.
 */
std::string CancelledState::getName()
{
    return "Cancelled";
}

/**
 * @brief Destroys the CancelledState object.
 */
CancelledState::~CancelledState()
{
}
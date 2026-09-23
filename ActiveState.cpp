#include "ActiveState.h"
#include "Incident.h"

/**
 * @brief Handles a dispatch request while the incident is active.
 *
 * The incident is already active, so no state transition occurs.
 *
 * @param incident The incident being handled.
 */
void ActiveState::handleDispatch(Incident *incident)
{
    (void)incident;
}

/**
 * @brief Handles a contain request while the incident is active.
 *
 * The incident is already being contained, so no state transition occurs.
 *
 * @param incident The incident being handled.
 */
void ActiveState::handleContain(Incident *incident)
{
    (void)incident;
}

/**
 * @brief Handles a resolve request while the incident is active.
 *
 * The incident can transition to the Resolved state.
 *
 * @param incident The incident being handled.
 */
void ActiveState::handleResolve(Incident *incident)
{
    (void)incident;
}

/**
 * @brief Handles a cancel request while the incident is active.
 *
 * @param incident The incident being handled.
 */
void ActiveState::handleCancel(Incident *incident)
{
    (void)incident;
}

/**
 * @brief Gets the name of the current state.
 *
 * @return The name of the state.
 */
std::string ActiveState::getName()
{
    return "Active";
}

/**
 * @brief Destroys the ActiveState object.
 */
ActiveState::~ActiveState()
{
}
#include "ReportedState.h"
#include "Incident.h"

/**
 * @brief Handles a dispatch request while the incident is reported.
 *
 * Changes the incident to the Dispatched state.
 *
 * @param incident The incident being handled.
 */
void ReportedState::handleDispatch(Incident* incident)
{
    if (incident != 0)
    {
        // The actual state transition is handled by Incident.
    }
}

/**
 * @brief Handles a contain request while the incident is reported.
 *
 * No state transition occurs because the incident
 * must first be dispatched.
 *
 * @param incident The incident being handled.
 */
void ReportedState::handleContain(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a resolve request while the incident is reported.
 *
 * An incident cannot be resolved before it has been dispatched
 * and contained.
 *
 * @param incident The incident being handled.
 */
void ReportedState::handleResolve(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Handles a cancel request while the incident is reported.
 *
 * @param incident The incident being handled.
 */
void ReportedState::handleCancel(Incident* incident)
{
    (void)incident;
}

/**
 * @brief Gets the name of the current state.
 *
 * @return The name of the state.
 */
std::string ReportedState::getName()
{
    return "Reported";
}

/**
 * @brief Destroys the ReportedState object.
 */
ReportedState::~ReportedState()
{
}
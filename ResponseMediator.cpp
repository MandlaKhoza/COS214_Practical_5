#include "ResponseMediator.h"

/**
 * @brief Destroys the mediator.
 *
 * ResponseMediator is a pure abstract base class, but the destructor
 * still needs a body because a derived destructor (e.g.
 * ResponseCoordinator::~ResponseCoordinator()) chains up to it during
 * destruction of any object deleted through a ResponseMediator*.
 */
ResponseMediator::~ResponseMediator()
{
}

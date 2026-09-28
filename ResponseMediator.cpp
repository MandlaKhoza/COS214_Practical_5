#include "ResponseMediator.h"

// Pure virtual base class - the destructor still needs a body because
// derived destructors (ResponseCoordinator::~ResponseCoordinator) chain
// up to it during destruction.
ResponseMediator::~ResponseMediator()
{
}

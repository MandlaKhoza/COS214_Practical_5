#include "IAccessControl.h"

/**
 * @brief Destroys the interface.
 *
 * Declared virtual in IAccessControl.h so that deleting a concrete
 * implementation (e.g. AccessControlAdapter) through an IAccessControl*
 * correctly invokes the derived class's destructor rather than only
 * this one.
 */
IAccessControl::~IAccessControl()
{
}

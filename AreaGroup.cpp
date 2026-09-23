#include "AreaGroup.h"
#include <algorithm>

/**
 * @brief Constructs an AreaGroup.
 *
 * @param name The name of the area group.
 */
AreaGroup::AreaGroup(std::string name)
    : AreaComponent(name)
{
}

/**
 * @brief Destroys the AreaGroup.
 *
 * The AreaGroup does not own the child AreaComponent objects,
 * so the child objects are not deleted here.
 */
AreaGroup::~AreaGroup()
{
}

/**
 * @brief Locks all child components in the area group.
 *
 * Each child is instructed to lock itself. This allows the
 * Composite to treat individual Zones and other AreaGroups
 * uniformly.
 */
void AreaGroup::lock()
{
    for (std::vector<AreaComponent*>::iterator it = children.begin();
         it != children.end();
         ++it)
    {
        if (*it != 0)
        {
            (*it)->lock();
        }
    }
}

/**
 * @brief Unlocks all child components in the area group.
 *
 * Each child is instructed to unlock itself.
 */
void AreaGroup::unlock()
{
    for (std::vector<AreaComponent*>::iterator it = children.begin();
         it != children.end();
         ++it)
    {
        if (*it != 0)
        {
            (*it)->unlock();
        }
    }
}

/**
 * @brief Checks whether all child components are locked.
 *
 * @return true if all children are locked, otherwise false.
 */
bool AreaGroup::isLocked()
{
    if (children.empty())
    {
        return false;
    }

    for (std::vector<AreaComponent*>::iterator it = children.begin();
         it != children.end();
         ++it)
    {
        if (*it != 0 && !(*it)->isLocked())
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Adds a child component to the area group.
 *
 * @param child The AreaComponent to add.
 */
void AreaGroup::add(AreaComponent* child)
{
    if (child != 0)
    {
        children.push_back(child);
    }
}

/**
 * @brief Removes a child component from the area group.
 *
 * @param child The AreaComponent to remove.
 */
void AreaGroup::remove(AreaComponent* child)
{
    std::vector<AreaComponent*>::iterator it =
        std::find(children.begin(), children.end(), child);

    if (it != children.end())
    {
        children.erase(it);
    }
}
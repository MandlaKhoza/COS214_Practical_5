#include "AreaComponent.h"
#include <iostream>
#include <string>

/**
 * @brief constructor for teh area component class
 * @param name describes the name of the area component that we are currently working on
 */
    AreaComponent::AreaComponent(std::string name)
    :name(name)
    {
        //no implemenatation
    }
/**
 * @brief destructor for the area componenet
 */
AreaComponent::~AreaComponent(){
    //no implementation since we dont have any dynamic memory to manage
}

/**
 * @brief getter function that retrieves the name of the area component
 */
std::string AreaComponent::getName(){
    return this->name; 
}
/**
 * @brief Adds a child to the area component.
 *
 * The base AreaComponent does not directly store children.
 * AreaGroup overrides this function to store child components.
 *
 * @param child The AreaComponent to add.
 */
void AreaComponent::add(AreaComponent* child)
{
    (void)child;
}

/**
 * @brief Removes a child from the area component.
 *
 * The base AreaComponent does not directly store children.
 * AreaGroup overrides this function to remove child components.
 *
 * @param child The AreaComponent to remove.
 */
void AreaComponent::remove(AreaComponent* child)
{
    (void)child;
}

/**
 * @brief Locks the area component.
 *
 * The base implementation does not perform a locking operation.
 * Derived classes provide the appropriate behaviour.
 */
void AreaComponent::lock()
{
}

/**
 * @brief Unlocks the area component.
 *
 * The base implementation does not perform an unlocking operation.
 * Derived classes provide the appropriate behaviour.
 */
void AreaComponent::unlock()
{
}

/**
 * @brief Checks whether the area component is locked.
 *
 * @return false because the base component has no locking state.
 */
bool AreaComponent::isLocked()
{
    return false;
}

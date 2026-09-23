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


#include "Drone.h"
/****************************************************************************/
/*!
\brief
Constructor of the Class Drone
*/
/****************************************************************************/
Drone::Drone() : 
Ship("Drone", 1, 8.0f, 1000.0f, "OBJ//Enemies//Drone.obj", "Image//Enemies//Drone.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 5000.0f, 30.0f, 1, 25.0f, PURPLE)
{

	SetRewardGold(3000);

}
/****************************************************************************/
/*!
\brief
Destructor of the Class Drone
*/
/****************************************************************************/
Drone::~Drone() {
}
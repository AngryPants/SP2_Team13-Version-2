#include "Drone.h"

/******************************************************************************************/
/*!

\brief
A default constructor for the drone.

*/
/******************************************************************************************/
Drone::Drone() :
Ship("Drone", 1, 8.0f, 1000.0f, "OBJ//Enemies//Drone.obj", "Image//Enemies//Drone.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 5000.0f, 30.0f, 1, 25.0f, PURPLE)
{

	SetRewardGold(3000);

}

/*******************************************************************************/
/*!

/brief
An empty destructor.

*/
/*******************************************************************************/
Drone::~Drone() {
}
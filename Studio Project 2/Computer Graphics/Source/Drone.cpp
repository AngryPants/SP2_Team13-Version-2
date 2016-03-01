#include "Drone.h"

Drone::Drone() : 
Ship("Drone", 1, 8.0f, 1000.0f, "OBJ//Enemies//Drone.obj", "Image//Enemies//Drone.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 6500.0f, 30.0f, 3, 25.0f, PURPLE)
{

	SetRewardGold(3000);

}

Drone::~Drone() {
}
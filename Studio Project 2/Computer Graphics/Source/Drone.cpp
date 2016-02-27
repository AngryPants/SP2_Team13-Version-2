#include "Drone.h"

Drone::Drone() : 
Ship("Drone", 1, 8.0f, 3000.0f, "OBJ//Enemies//Drone.obj", "Image//Enemies//Drone.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 3000.0f, 30.0f, 4, 75.0f, PURPLE)
{
}

Drone::~Drone() {
}
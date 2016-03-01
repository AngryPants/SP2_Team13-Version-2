#include "Alien.h"

Alien::Alien() : 
Ship("Alien", 2, 10.0f, 9000.0f, "OBJ//Enemies//Alien.obj", "Image//Enemies//Alien.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 6500.0f, 30.0f, 12, 150.0f, BLUE)
{

	SetRewardGold(6000);

}

Alien::~Alien() {
}
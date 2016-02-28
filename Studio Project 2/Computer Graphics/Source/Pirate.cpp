#include "Pirate.h"

Pirate::Pirate() : 
Ship("Pirate", 2, 10.0f, 3000.0f, "OBJ//Enemies//Pirate.obj", "Image//Enemies//Pirate.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 3000.0f, 30.0f, 5, 100.0f, RED)
{
}

Pirate::~Pirate() {
}
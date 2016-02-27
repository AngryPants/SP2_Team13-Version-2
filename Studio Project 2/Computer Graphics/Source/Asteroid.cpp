#include "Asteroid.h"

Asteroid::Asteroid(string name, float mass, int minimumDamage, const char* textureFile, float health, int ID)
: SpaceObject(name, "OBJ//Asteroid//Asteroid.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::CEMENT], mass, 20.0f, health, ID)
{

	this->minimumDamage = minimumDamage;

}

Asteroid::~Asteroid() {
}
#include "Asteroid.h"

Asteroid::Asteroid(string name, float mass, int minimumDamage, const char* textureFile, float health, int ID)
: SpaceObject(name, "OBJ//Asteroid//Asteroid.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::CEMENT], mass, 20.0f, health, ID)
{

	SetMinimumDamage(minimumDamage);

}

Asteroid::~Asteroid() {
}

//Getters
int Asteroid::GetMinimumDamage() {

	return minimumDamage;

}

//Setters
void Asteroid::SetMinimumDamage(int minimumDamage) {

	if (minimumDamage >= 0) {
	
		this->minimumDamage = minimumDamage;	

	} else {
	
		this->minimumDamage = 0;
	
	}

}
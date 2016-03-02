#include "Asteroid.h"

Asteroid::Asteroid(string name, float mass, int minimumDamage, const char* textureFile, float health, int ID)
: SpaceObject(name, "OBJ//Asteroid//Asteroid.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::CEMENT], mass, 60.0f, health, ID)
{

	SetMinimumDamage(minimumDamage);
	maxRadius = 60.0f;

}

Asteroid::~Asteroid() {
}

//Getters
int Asteroid::GetMinimumDamage() {

	return minimumDamage;

}

float Asteroid::GetMaxRadius() {

	return this->maxRadius;

}

//Setters
void Asteroid::SetMinimumDamage(int minimumDamage) {

	if (minimumDamage >= 0) {
	
		this->minimumDamage = minimumDamage;	

	} else {
	
		this->minimumDamage = 0;
	
	}

}
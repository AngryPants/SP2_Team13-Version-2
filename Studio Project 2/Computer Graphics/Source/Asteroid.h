#ifndef _ASTEROID_H
#define _ASTEROID_H

#include "SpaceObject.h"

class Asteroid : public SpaceObject {

private:
	int minimumDamage;
	float maxRadius;

public:
	//Constructor & Destructor
	Asteroid(string name, float mass, int minimumDamage, const char* textureFile, float health, int ID);
	~Asteroid();

	//Getters
	int GetMinimumDamage();
	float GetMaxRadius();

	//Setters
	void SetMinimumDamage(int minimumDamage);

};
#endif
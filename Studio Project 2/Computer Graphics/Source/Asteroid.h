#ifndef _ASTEROID_H
#define _ASTEROID_H

#include "SpaceObject.h"

class Asteroid : public SpaceObject {

public:
	int minimumDamage;

	//Constructor & Destructor
	~Asteroid();

protected:
	Asteroid(string name, float mass, int minimumDamage, const char* textureFile, float health, int ID);

};
#endif
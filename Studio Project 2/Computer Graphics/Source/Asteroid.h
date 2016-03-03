#ifndef _ASTEROID_H
#define _ASTEROID_H

#include "SpaceObject.h"

class Asteroid : public SpaceObject {

private:
	float maxRadius;

public:
	//Constructor & Destructor
	Asteroid(string name, float mass, const char* textureFile, float health, int ID);
	~Asteroid();

	//Getters
	float GetMaxRadius();

	//Setters
	void SetMaxRadius(float radius);

};
#endif
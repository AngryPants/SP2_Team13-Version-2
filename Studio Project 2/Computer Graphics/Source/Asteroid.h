#ifndef _ASTEROID_H
#define _ASTEROID_H
/****************************************************************************/
/*!
\file Asteroid.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "SpaceObject.h"
/*****************************************/
/*!
		Class Asteroid
\brief

*/
/*****************************************/

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
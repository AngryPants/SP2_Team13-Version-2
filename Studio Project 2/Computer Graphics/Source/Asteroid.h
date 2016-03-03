#ifndef _ASTEROID_H
#define _ASTEROID_H
/****************************************************************************/
/*!
\file Asteroid.h
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
Class that defines the maximum radii of the asteroids
*/
/****************************************************************************/
#include "SpaceObject.h"
/*****************************************/
/*!
		Class Asteroid
\brief
defines the maximum radii of the asteroids
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
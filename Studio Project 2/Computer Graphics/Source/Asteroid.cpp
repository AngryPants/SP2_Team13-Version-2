/****************************************************************************/
/*!
\file Asteroid.cpp
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
CPP file for Asteroid
*/
/****************************************************************************/

#include "Asteroid.h"
/*******************************************************************************/
/*!

\brief
A constructor for Asteroids

\param name
The name of the asteroid.

\param mass
The mass of the asteroid

\param textureFile
The texture of the asteroid

\param health
The health of the asteroid

\param ID
the ID number of the asteroid

*/
/*******************************************************************************/
Asteroid::Asteroid(string name, float mass, const char* textureFile, float health, int ID)
: SpaceObject(name, "OBJ//Asteroid//Asteroid.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::CEMENT], mass, 60.0f, health, ID)
{

	SetMaxRadius(60.0f);

}
//Destructor


/*******************************************************************************/
/*!

\brief
An empty destructor

*/
/*******************************************************************************/
Asteroid::~Asteroid() {
}

//Getters
/*******************************************************************************/
/*!

\brief
Gets the maximum radius of the asteroid. Used when reseting the size of the asteroid.

\return
The maximum radius of the asteroid

*/
/*******************************************************************************/
float Asteroid::GetMaxRadius() {

	return this->maxRadius;

}

//Setters
/*******************************************************************************/
/*!

\brief
Sets the maximum radius of the asteroid.

\param radius
The new maximum radius of the asteroid.

*/
/*******************************************************************************/
void Asteroid::SetMaxRadius(float radius) {

	if (radius >= 0.1f) {
	
		this->maxRadius = radius;

	}

}
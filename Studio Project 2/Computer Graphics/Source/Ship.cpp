/****************************************************************************/
/*!
\file Ship.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for Ship

*/
/****************************************************************************/
#include "Ship.h"

/****************************************************************************************/
/*!

\brief
The constructor of Ship.

\param name
The name of the Ship.

\param int
The ID of the Ship.

\param radius
The radius of the Ship.

\param health
The health of the Ship.

\param meshFile
The file path of the OBJ.

\param textureFile
The file path of the texture.

\param material
The material of the mesh.

\param mass
The mass of the Ship.

\param maxSpeed
The maximum speed of the Ship.

\param fireRate
The fire rate of the Ship.

\param damage
The damage of the Ship.

\param bulletColour
The colour of the Ship's bullet.

*/
/****************************************************************************************/
Ship::Ship(string name, int ID, float radius, float health, string meshFile, const char* textureFile, Material material, float mass, float maxSpeed, int fireRate, int damage, BULLET_COLOUR bulletColour)
: SpaceObject(name, meshFile, textureFile, material, mass, radius, health, ID)
{

	this->damage = damage;
	this->maxSpeed = maxSpeed;
	this->fireRate = fireRate;
	this->timeToFire = 0.0f;
	this->bulletColour = bulletColour;

}

//Destructor

/****************************************************************************/
/*!
\brief
Destructor of the Class Ship
*/
/****************************************************************************/
Ship::~Ship() {
}

//Functions

/****************************************************************************/
/*!
\brief
Update function of the Class Kernite
\param &dt
A double reference value also known as Delta Time
*/
/****************************************************************************/
void Ship::Update(double &dt) {

	UpdateTimeToFire(dt);
	UpdateBullets(dt);

}
/****************************************************************************/
/*!
\brief
Update the variables of bullets with respect to Delta Time
\param &dt
A double reference value also known as Delta Time
*/
/****************************************************************************/
void Ship::UpdateBullets(double &dt) {

	for (list<Bullet>::iterator iter = bullets.begin(); iter != bullets.end();) {
	
		if (iter->ShouldDelete()) {
		
			iter = bullets.erase(iter);

		} else {
			
			iter->Update(dt);
			++iter;

		}

	}

}
/****************************************************************************/
/*!
\brief
Assigns the textureFile and limit the firing speed
\param bulletPosition
A vector of the position of the bullet
*/
/****************************************************************************/
void Ship::Shoot(Vector3 bulletPosition) {

	const char* textureFile;

	switch (bulletColour) {
	
		case GREEN:
			textureFile = "Image//Bullet//Bullet_Green.tga";
			break;

		case BLUE:
			textureFile = "Image//Bullet//Bullet_Blue.tga";
			break;

		case RED:
			textureFile = "Image//Bullet//Bullet_Red.tga";
			break;

		case ORANGE:
			textureFile = "Image//Bullet//Bullet_Orange.tga";
			break;

		case YELLOW:
			textureFile = "Image//Bullet//Bullet_Yellow.tga";
			break;

		case PURPLE:
			textureFile = "Image//Bullet//Bullet_Purple.tga";
			break;

		default:
			textureFile = "Image//Bullet//Bullet_Red.tga";
			break;

	}

	if (timeToFire <= 0.0f) {

		Bullet bullet = Bullet(bulletPosition, GetRotationMatrix(), GetDamage(), textureFile, GetVelocity().Length() + 1000.0f);
		bullets.push_back(bullet);
		timeToFire = 1.0f/fireRate;

	}

}
/****************************************************************************/
/*!
\brief
Overloaded function to call the other Shoot function
*/
/****************************************************************************/
void Ship::Shoot() {

	Shoot(GetPosition() + (GetForwardVector() * (GetRadius()/2.0f + 2.0f)));

}
/****************************************************************************/
/*!
\brief
Checks if the next bullet can be fired
\param dt
A double reference value also known as Delta Time
*/
/****************************************************************************/
void Ship::UpdateTimeToFire(double &dt) {

	if (timeToFire > 0.0f) {
		
		if (timeToFire < dt) {
		
			timeToFire = 0.0f;

		} else {
		
			timeToFire -= dt;

		}

	}

}

//Getters

/****************************************************************************/
/*!
\brief
Getter of the value maxSpeed
\return
Returns the maxSpeed of the Class Ship
*/
/****************************************************************************/
float Ship::GetMaxSpeed() {

	return this->maxSpeed;

}
/****************************************************************************/
/*!
\brief
Getter of the value fireRate
\return
Returns the fireRate of the Class Ship
*/
/****************************************************************************/
float Ship::GetFireRate() {

	return this->fireRate;

}
/****************************************************************************/
/*!
\brief
Getter of the value damage
\return
Returns the damage of the Class Ship
*/
/****************************************************************************/
int Ship::GetDamage() {

	return this->damage;

}
/****************************************************************************/
/*!
\brief
Getter of the list pointer bullets
\return
Returns the reference of the list pointer of the Class Ship
*/
/****************************************************************************/
list<Bullet>* Ship::GetBullets() {

	return &this->bullets;

}
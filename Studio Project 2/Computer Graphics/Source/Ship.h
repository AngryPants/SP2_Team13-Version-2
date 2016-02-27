#ifndef _SHIP_H
#define _SHIP_H

#include "SpaceObject.h"
#include "Bullet.h"
#include <list>
#include "Physics.h"

using std::list;

enum BULLET_COLOUR {

	GREEN,
	BLUE,
	RED,
	ORANGE,
	YELLOW,
	PURPLE,

	NUM_COLOUR,

};

class Ship : public SpaceObject {

protected:
	float maxSpeed;
	float fireRate;
	float timeToFire;
	int damage;
	list<Bullet> bullets;
	BULLET_COLOUR bulletColour;

	//Constructor
	Ship(string name, int ID, float radius, float health, string meshFile, const char* textureFile, Material material, float mass, float maxSpeed, int fireRate, int damage, BULLET_COLOUR bulletColour);

public:
	//Destructor
	virtual ~Ship();

	//Functions
	void Update(double &dt);
	void UpdateBullets(double &dt);
	void UpdateTimeToFire(double &dt);
	void Shoot(Vector3 bulletPosition);
	void Shoot();

	//Getters
	float GetMaxSpeed();
	float GetFireRate();
	int GetDamage();
	list<Bullet>* GetBullets();

};

#endif
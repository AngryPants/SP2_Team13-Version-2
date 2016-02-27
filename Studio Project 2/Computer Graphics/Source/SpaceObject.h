#ifndef _SPACEOBJECT_H
#define _SPACEOBJECT_H

#include "RigidBody.h"

class SpaceObject : public RigidBody {

protected:
	//Variables
	unsigned int ID;
	float health;

public:
	//Constructor & Destructor
	SpaceObject(string name, string meshFile, const char* textureFile, Material material, float mass, float radius, float health, int ID);
	~SpaceObject();

	//Functions
	void AddHealth(float addAmount);
	void DecreaseHealth(float decreaseAmount);

	//Is-ters
	bool isDead();

	//Getters
	float GetHealth();
	unsigned int GetID();

	//Setters
	void SetHealth(float health);
	void SetID(unsigned int ID);

};

#endif
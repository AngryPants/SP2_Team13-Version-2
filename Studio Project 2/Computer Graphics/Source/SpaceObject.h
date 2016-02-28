#ifndef _SPACEOBJECT_H
#define _SPACEOBJECT_H

#include "RigidBody.h"

class SpaceObject : public RigidBody {

protected:
	//Variables
	unsigned int ID;
	float health;
	float maxHealth;

	//Constructor
	SpaceObject(string name, string meshFile, const char* textureFile, Material material, float mass, float radius, float health, int ID);

public:
	//Destructor
	~SpaceObject();

	//Functions
	void AddHealth(float addAmount);
	void DecreaseHealth(float decreaseAmount);
	void Spawn();
	void Spawn(Vector3 position);
	void Spawn(float x, float y, float z);
	void Despawn();

	//Is-ters
	bool IsDead();

	//Getters
	float GetHealth();
	unsigned int GetID();

	//Setters
	void SetHealth(float health);
	void SetID(unsigned int ID);

};

#endif
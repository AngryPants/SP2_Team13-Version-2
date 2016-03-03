#ifndef _SPACEOBJECT_H
#define _SPACEOBJECT_H
/****************************************************************************/
/*!
\file SpaceObject.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for SpaceObject

*/
/****************************************************************************/
#include "RigidBody.h"
#include "Item.h"
/******************************************************************************/
/*!
		Class SpaceObject:
\brief
Defines a SpaceObject, a child class of RigidBody.

*/
/******************************************************************************/
class SpaceObject : public RigidBody {

protected:
	//Variables
	unsigned int ID;
	float health;
	float maxHealth;
	Item rewardItem;
	int numItems;
	int rewardGold;

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
	float GetMaxHealth();
	unsigned int GetID();
	Item GetRewardItem();
	int GetRewardGold();
	int GetNumberOfRewardItems();

	//Setters
	void SetHealth(float health);
	void SetMaxHealth(float health);
	void SetID(unsigned int ID);
	void SetRewardItem(Item item, int numItems);
	void SetRewardGold(int gold);

};

#endif
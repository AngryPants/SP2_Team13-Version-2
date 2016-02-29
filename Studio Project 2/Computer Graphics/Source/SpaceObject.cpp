#include "SpaceObject.h"

//Constructor
SpaceObject::SpaceObject(string name, string meshFile, const char* textureFile, Material material, float mass, float radius, float health, int ID) 
: RigidBody(name, meshFile, textureFile, material, mass, radius)
{

	SetID(ID);
	SetHealth(health);
	this->maxHealth = this->health;
	this->numItems = 0;
	this->rewardGold = 0;

}

//Functions
void SpaceObject::AddHealth(float addAmount) {

	if (addAmount > 0.0f) {
	
		health += addAmount;

	}

}

void SpaceObject::DecreaseHealth(float decreaseAmount) {

	if (decreaseAmount > 0.0f) {
	
		if (decreaseAmount >= health) {
		
			health = 0.0f;

		} else {
		
			health -= decreaseAmount;

		}

	}

}

void SpaceObject::Spawn() {

	Spawn(GetPosition());

}

void SpaceObject::Spawn(Vector3 position) {

	Enable();
	SetPosition(position);
	health = maxHealth;

}

void SpaceObject::Spawn(float x, float y, float z) {

	Spawn(Vector3(x, y, z));

}

void SpaceObject::Despawn() {

	Disable();

}

//Destructor
SpaceObject::~SpaceObject() {
}

//Is-ters
bool SpaceObject::IsDead() {

	if (health > Math::EPSILON) {
	
		return false;

	}

	return true;

}

//Getters
float SpaceObject::GetHealth() {

	return this->health;

}

float SpaceObject::GetMaxHealth() {

	return this->maxHealth;

}

unsigned int SpaceObject::GetID() {

	return this->ID;

}

Item SpaceObject::GetRewardItem() {

	return this->rewardItem;

}

int SpaceObject::GetNumberOfRewardItems() {

	return this->numItems;

}

int SpaceObject::GetRewardGold() {

	return this->rewardGold;

}

//Setters
void SpaceObject::SetHealth(float health) {

	if (health >= 0.0f) {
	
		this->health = health;

	} else {
	
		this->health = 0.0f;

	}

}

void SpaceObject::SetMaxHealth(float health) {

	if (health >= 0.0f) {
	
		this->maxHealth = health;

	}

	if (this->health > this->maxHealth) {
	
		this->health = this->maxHealth;

	}

}

void SpaceObject::SetID(unsigned int ID) {

	this->ID = ID;

}

void SpaceObject::SetRewardItem(Item item, int numItems) {

	this->rewardItem = item;

	if (numItems > 0) {
		
		this->numItems = numItems;

	} else {
	
		this->numItems = 0;

	}

}

void SpaceObject::SetRewardGold(int gold) {

	if (gold > 0) {
	
		this->rewardGold = gold;

	} else {

		this->rewardGold = 0;

	}

}
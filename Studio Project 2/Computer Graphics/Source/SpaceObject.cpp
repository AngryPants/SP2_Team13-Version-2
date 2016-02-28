#include "SpaceObject.h"

//Constructor
SpaceObject::SpaceObject(string name, string meshFile, const char* textureFile, Material material, float mass, float radius, float health, int ID) 
: RigidBody(name, meshFile, textureFile, material, mass, radius)
{

	SetID(ID);
	SetHealth(health);
	this->maxHealth = this->health;

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

unsigned int SpaceObject::GetID() {

	return this->ID;

}

//Setters
void SpaceObject::SetHealth(float health) {

	if (health >= 0.0f) {
	
		this->health = health;

	} else {
	
		this->health = 0.0f;

	}

}

void SpaceObject::SetID(unsigned int ID) {

	this->ID = ID;

}
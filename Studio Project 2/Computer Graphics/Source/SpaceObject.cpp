#include "SpaceObject.h"

/*************************************************************************************************************************/
/*!

\brief
A constructor of SpaceObject.

\param name
The name of the SpaceObject.

\param meshFile
The file path of the OBJ.

\param textureFile
The file path of the texture.

\param material
The material of the mesh.

\param mass
The mass of the SpaceObject.

\param radius
The radius of the SpaceObject.

\param health
The health of the SpaceObject.

\param ID
The ID of the SpaceObject.

*/
/*************************************************************************************************************************/
SpaceObject::SpaceObject(string name, string meshFile, const char* textureFile, Material material, float mass, float radius, float health, int ID) 
: RigidBody(name, meshFile, textureFile, material, mass, radius)
{

	SetID(ID);
	SetHealth(health);
	this->maxHealth = this->health;
	this->numItems = 0;
	this->rewardGold = 0;

}

/*************************************************************************************************************************/
/*!

\brief
An empty destructor.

*/
/*************************************************************************************************************************/
SpaceObject::~SpaceObject() {
}

//Functions
/*************************************************************************************************************************/
/*!

\brief
Adds health to the SpaceObject.

\param addAmount
The amount of the health to add to the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::AddHealth(float addAmount) {

	if (addAmount > 0.0f) {
	
		health += addAmount;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Decreases health from the SpaceObject.

\param addAmount
The amount of the health to decrease from the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::DecreaseHealth(float decreaseAmount) {

	if (decreaseAmount > 0.0f) {
	
		if (decreaseAmount >= health) {
		
			health = 0.0f;

		} else {
		
			health -= decreaseAmount;

		}

	}

}

/*************************************************************************************************************************/
/*!

\brief
Spawns the SpawnObject by enabling it, as well as setting its health to full health.

\param position
The position to set the SpawnObject to.

*/
/*************************************************************************************************************************/
void SpaceObject::Spawn(Vector3 position) {

	Enable();
	SetPosition(position);
	health = maxHealth;

}

/*************************************************************************************************************************/
/*!

\brief
Spawns the SpawnObject by enabling it, as well as setting its health to full health. The SpaceObject remains at its current position.

*/
/*************************************************************************************************************************/
void SpaceObject::Spawn() {

	Spawn(GetPosition());

}

/*************************************************************************************************************************/
/*!

\brief
Spawns the SpawnObject by enabling it, as well as setting its health to full health.

\param x
The x position to set the SpawnObject to.

\param y
The y position to set the SpawnObject to.

\param z
The z position to set the SpawnObject to.

*/
/*************************************************************************************************************************/
void SpaceObject::Spawn(float x, float y, float z) {

	Spawn(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Disables the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::Despawn() {

	Disable();

}

//Is-ters
/*************************************************************************************************************************/
/*!

\brief
Checks if the SpaceObject is dead.

\return
Returns a true if the SpaceObject is dead or a false if it is not dead.

*/
/*************************************************************************************************************************/
bool SpaceObject::IsDead() {

	if (health > Math::EPSILON) {
	
		return false;

	}

	return true;

}

//Getters
/*************************************************************************************************************************/
/*!

\brief
Gets the current health of the SpaceObject.

\return
Returns the current health of the SpaceObject.

*/
/*************************************************************************************************************************/
float SpaceObject::GetHealth() {

	return this->health;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the max health of the SpaceObject.

\return
Returns the max health of the SpaceObject.

*/
/*************************************************************************************************************************/
float SpaceObject::GetMaxHealth() {

	return this->maxHealth;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the ID of the SpaceObject.

\return
Returns the ID of the SpaceObject.

*/
/*************************************************************************************************************************/
unsigned int SpaceObject::GetID() {

	return this->ID;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the reward item of the SpaceObject.

\return
Returns the reward item of the SpaceObject.

*/
/*************************************************************************************************************************/
Item SpaceObject::GetRewardItem() {

	return this->rewardItem;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the number of reward items of the SpaceObject.

\return
Returns the number of reward items of the SpaceObject.

*/
/*************************************************************************************************************************/
int SpaceObject::GetNumberOfRewardItems() {

	return this->numItems;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the amount of reward gold of the SpaceObject.

\return
Returns the amount of reward gold of the SpaceObject.

*/
/*************************************************************************************************************************/
int SpaceObject::GetRewardGold() {

	return this->rewardGold;

}

//Setters
/*************************************************************************************************************************/
/*!

\brief
Sets the current health of the SpaceObject.

\param health
The new current health of the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::SetHealth(float health) {

	if (health >= 0.0f) {
	
		this->health = health;

	} else {
	
		this->health = 0.0f;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Sets the max health of the SpaceObject.

\param health
The new max health of the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::SetMaxHealth(float health) {

	if (health >= 0.0f) {
	
		this->maxHealth = health;

	}

	if (this->health > this->maxHealth) {
	
		this->health = this->maxHealth;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Sets the ID of the SpaceObject.

\param health
The new ID of the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::SetID(unsigned int ID) {

	this->ID = ID;

}

/*************************************************************************************************************************/
/*!

\brief
Sets the reward item of the SpaceObject.

\param health
The new reward item of the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::SetRewardItem(Item item, int numItems) {

	this->rewardItem = item;

	if (numItems > 0) {
		
		this->numItems = numItems;

	} else {
	
		this->numItems = 0;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Sets the reward gold of the SpaceObject.

\param health
The new reward gold of the SpaceObject.

*/
/*************************************************************************************************************************/
void SpaceObject::SetRewardGold(int gold) {

	if (gold > 0) {
	
		this->rewardGold = gold;

	} else {

		this->rewardGold = 0;

	}

}
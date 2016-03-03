#include "Bullet.h"

/**********************************************************************************************************************/
/*!

\brief
Constructor for Bullet.

\param position
The spawn position of the Bullet.

\param rotationMatrix
The rotation of the Bullet.

\param damage
The damage of the Bullet.

\param textureFile
The file path of the texture.

\param speed
The speed of the bullet.

*/
/**********************************************************************************************************************/
Bullet::Bullet(Vector3 position, Mtx44 rotationMatrix, int damage, const char* textureFile, float speed)
: GameObject("Bullet", "OBJ//Bullet//Bullet.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{
	SetPosition(position);
	SetRotation(rotationMatrix);
	SetDamage(damage);
	SetSpeed(speed);
	timeToDespawn = 5.0;

}

/**********************************************************************************************************************/
/*!

\brief
Constructor for Bullet.

\param position
The spawn position of the Bullet.

\param rotationMatrix
The rotation of the Bullet.

\param damage
The damage of the Bullet.

\param textureFile
The file path of the texture.

*/
/**********************************************************************************************************************/
Bullet::Bullet(Vector3 position, Mtx44 rotationMatrix, int damage, const char* textureFile)
: GameObject("Bullet", "OBJ//Bullet//Bullet.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	SetPosition(position);
	SetRotation(rotationMatrix);
	SetDamage(damage);
	SetSpeed(1200.0f);
	timeToDespawn = 5.0;

}

/**********************************************************************************************************************/
/*!

\brief
An empty destructor.

*/
/**********************************************************************************************************************/
Bullet::~Bullet() {
}

//Functions
/**********************************************************************************************************************/
/*!

\brief
Updates the Bullet.

\param dt
The time taken for this frame to complete.

*/
/**********************************************************************************************************************/
void Bullet::Update(double &dt) {

	UpdatePosition(dt);
	
	if (timeToDespawn > 0.0f) {
	
		timeToDespawn -= dt;

	}

}

/**********************************************************************************************************************/
/*!

\brief
Updates the position of the Bullet.

\param dt
The time taken for this frame to complete.

*/
/**********************************************************************************************************************/
void Bullet::UpdatePosition(double &dt) {

	Translate(GetForwardVector() * speed * dt);

}

/**********************************************************************************************************************/
/*!

\brief
Despawns the Bullet.

*/
/**********************************************************************************************************************/
void Bullet::Despawn() {

	timeToDespawn = 0.0f;

}

/**********************************************************************************************************************/
/*!

\brief
Get whether or not the Bullet should be deleted.

*/
/**********************************************************************************************************************/
bool Bullet::ShouldDelete() {

	if (timeToDespawn <= 0.0f) {
	
		return true;

	}

	return false;

}

//Getters
/**********************************************************************************************************************/
/*!

\brief
Gets the damage of the Bullet.

\return
Returns the damage of the Bullet.

*/
/**********************************************************************************************************************/
int Bullet::GetDamage() {

	return this->damage;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the speed of the Bullet.

\return
Returns the speed of the Bullet.

*/
/**********************************************************************************************************************/
float Bullet::GetSpeed() {

	return this->speed;

}

//Setters
/**********************************************************************************************************************/
/*!

\brief
Sets the damage of the Bullet.

\param damage
The new damage of the Bullet.

*/
/**********************************************************************************************************************/
void Bullet::SetDamage(int damage) {

	if (damage > 0) {

		this ->damage = damage;

	} else {
	
		this->damage = 0;

	}

}

/**********************************************************************************************************************/
/*!

\brief
Sets the speed of the Bullet.

\param damage
The new speed of the Bullet.

*/
/**********************************************************************************************************************/
void Bullet::SetSpeed(float speed) {

	if (speed > 0.0f) {
	
		this->speed = speed;

	} else {
	
		this->speed = 0.0f;

	}

}
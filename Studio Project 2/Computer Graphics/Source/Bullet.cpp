#include "Bullet.h"

//Constructors
Bullet::Bullet(Vector3 position, Mtx44 rotationMatrix, int damage, const char* textureFile, float speed)
: GameObject("Bullet", "OBJ//Bullet//Bullet.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{
	SetPosition(position);
	SetRotation(rotationMatrix);
	SetDamage(damage);
	SetSpeed(speed);
	removeBullet = false;
	timeToDespawn = 5.0;

}

Bullet::Bullet(Vector3 position, Mtx44 rotationMatrix, int damage, const char* textureFile)
: GameObject("Bullet", "OBJ//Bullet//Bullet.obj", textureFile, MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	SetPosition(position);
	SetRotation(rotationMatrix);
	SetDamage(damage);
	SetSpeed(1200.0f);
	removeBullet = false;
	timeToDespawn = 5.0;

}

//Destructor
Bullet::~Bullet() {
}

//Functions
void Bullet::Update(double &dt) {

	UpdatePosition(dt);
	timeToDespawn -= dt;

	if (timeToDespawn <= 0.0) {
	
		Despawn();

	}

}

void Bullet::UpdatePosition(double &dt) {

	Translate(GetForwardVector() * speed * dt);

}

void Bullet::Despawn() {

	removeBullet = true;

}

bool Bullet::ShouldDelete() {

	if (removeBullet) {
	
		return true;

	}

	return false;

}

//Getters
int Bullet::GetDamage() {

	return this->damage;

}

float Bullet::GetSpeed() {

	return this->speed;

}

//Setters
void Bullet::SetDamage(int damage) {

	if (damage > 0) {

		this ->damage = damage;

	} else {
	
		this->damage = 0;

	}

}

void Bullet::SetSpeed(float speed) {

	if (speed > 0.0f) {
	
		this->speed = speed;

	} else {
	
		this->speed = 0.0f;

	}

}
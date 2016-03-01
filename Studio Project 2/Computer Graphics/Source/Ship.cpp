#include "Ship.h"

//Constructor
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
Ship::~Ship() {
}

//Functions
void Ship::Update(double &dt) {

	UpdateTimeToFire(dt);
	UpdateBullets(dt);

}

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

		Bullet bullet = Bullet(bulletPosition, GetRotationMatrix(), GetDamage(), textureFile, GetVelocity().Length() + 500.0f);
		bullets.push_back(bullet);
		timeToFire = 1.0f/fireRate;

	}

}

void Ship::Shoot() {

	Shoot(GetPosition() + (GetForwardVector() * (GetRadius()/2.0f + 2.0f)));

}

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
float Ship::GetMaxSpeed() {

	return this->maxSpeed;

}

float Ship::GetFireRate() {

	return this->fireRate;

}

int Ship::GetDamage() {

	return this->damage;

}

list<Bullet>* Ship::GetBullets() {

	return &this->bullets;

}
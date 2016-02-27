#include "PlayerShip.h"

//Constructor
PlayerShip::PlayerShip()
: Ship("Condor", 0, 8.0f, 1000.0f, "OBJ//Condor//Condor.obj", "Image//Condor//Condor.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 6000, 25.0f, 5, 100, GREEN)
{

	upgrades[Upgrade::WEAPON] = nullptr;
	upgrades[Upgrade::ARMOUR] = nullptr;
	upgrades[Upgrade::ENGINE] = nullptr;

	speed = 0.0f;

}

//Destructor
PlayerShip::~PlayerShip() {
}

void PlayerShip::IncreaseSpeed(float increaseAmount) {

	if (increaseAmount > 0.0f) {
	
		speed += increaseAmount;

		if (speed > GetMaxSpeed()) {
		
			SetSpeed(GetMaxSpeed());

		}

	}

}

void PlayerShip::DecreaseSpeed(float decreaseAmount) {

	if (decreaseAmount > 0.0f) {

		speed -= decreaseAmount;

		if (speed < 0.0f) {
		
			SetSpeed(0.0f);

		}

	}

}

//Getters
float PlayerShip::GetSpeed() {

	return this->speed;

}

//Setters
void PlayerShip::SetSpeed(float newSpeed) {

	if (newSpeed > GetMaxSpeed()) {
	
		this->speed = GetMaxSpeed();

	} else if (newSpeed < 0.0f) {
	
		this->speed = 0.0f;

	} else {
	
		this->speed = newSpeed;

	}

}
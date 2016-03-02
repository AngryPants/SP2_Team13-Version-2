#include "PlayerShip.h"

//Constructor
PlayerShip::PlayerShip()
: Ship("Condor", 0, 8.0f, 5000.0f, "OBJ//Condor//Condor.obj", "Image//Condor//Condor.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 6000.0f, 75.0f, 8, 400, YELLOW)
{

	upgrades[Upgrade::WEAPON] = nullptr;
	upgrades[Upgrade::ARMOUR] = nullptr;
	upgrades[Upgrade::ENGINE] = nullptr;

	isMining = false;
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

void PlayerShip::Update(double &dt) {

	UpdateTimeToFire(dt);
	UpdateBullets(dt);
	miningLaser.SetRotation(GetRotationMatrix());
	miningLaser.SetPosition(GetPosition() + GetForwardVector() * GetRadius());

}

//Is-ters
bool PlayerShip::IsMining() {

	return this->isMining;

}

//Getters
float PlayerShip::GetSpeed() {

	return this->speed;

}

MiningLaser* PlayerShip::GetMiningLaser() {

	return &(this->miningLaser);	

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

void PlayerShip::SetMining(bool isMining) {

	this->isMining = isMining;
	
}
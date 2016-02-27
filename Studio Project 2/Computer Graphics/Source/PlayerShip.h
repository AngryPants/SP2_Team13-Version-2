#ifndef _PLAYERSHIP_H
#define _PLAYERSHIP_H

#include "Ship.h"
#include "Upgrade.h"
#include "MousePosition.h"
#include "Application.h"

class PlayerShip : public Ship {

private:
	//Variables
	float speed;
	Upgrade* upgrades[Upgrade::NUM_UPGRADE];

public:
	//Constructors & Destructor
	PlayerShip();
	~PlayerShip();

	//Functions
	void IncreaseSpeed(float increaseAmount);
	void DecreaseSpeed(float decreaseAmount);

	//Getters
	float GetSpeed();

	//Setters
	void SetSpeed(float newSpeed);

};

#endif
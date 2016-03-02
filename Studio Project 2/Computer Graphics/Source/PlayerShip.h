#ifndef _PLAYERSHIP_H
#define _PLAYERSHIP_H

#include "Ship.h"
#include "Upgrade.h"
#include "Application.h"
#include "MiningLaser.h"

class PlayerShip : public Ship {

private:
	//Variables
	float speed;
	Upgrade* upgrades[Upgrade::NUM_UPGRADE];
	MiningLaser miningLaser;
	bool isMining;

public:
	//Constructors & Destructor
	PlayerShip();
	~PlayerShip();

	//Functions
	void Update(double &dt);
	void IncreaseSpeed(float increaseAmount);
	void DecreaseSpeed(float decreaseAmount);

	//Is-ters
	bool IsMining();

	//Getters
	float GetSpeed();
	MiningLaser* GetMiningLaser();

	//Setters
	void SetSpeed(float newSpeed);
	void SetMining(bool isMining);

};

#endif
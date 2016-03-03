#ifndef _PLAYERSHIP_H
#define _PLAYERSHIP_H
/****************************************************************************/
/*!
\file PlayerShip.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "Ship.h"
#include "Application.h"
#include "MiningLaser.h"
/******************************************************************************/
/*!
		Class PlayerShip:
\brief
*/
/******************************************************************************/
class PlayerShip : public Ship {

private:
	//Variables
	float speed;
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
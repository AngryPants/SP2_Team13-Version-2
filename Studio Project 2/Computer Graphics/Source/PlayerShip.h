#ifndef _PLAYERSHIP_H
#define _PLAYERSHIP_H
/****************************************************************************/
/*!

\file PlayerShip.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for PlayerShip

*/
/****************************************************************************/
#include "Ship.h"
#include "Application.h"
#include "MiningLaser.h"
/******************************************************************************/
/*!
		Class PlayerShip:
\brief
Defines PlayerShip, a child class of ship.

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
#ifndef _MINING_H
#define _MINING_H
/****************************************************************************/
/*!
\file Mining.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Mining

*/
/****************************************************************************/
#include "Asteroid.h"
#include "PlayerShip.h"
#include "Collision.h"
/******************************************************************************/
/*!
		Class Mining:
\brief	
Defines Mining, a struct that stores the static functions used to mine Asteroids.

*/
/******************************************************************************/
struct Mining {

public:
	static void Mine(PlayerShip* playerShip, Asteroid* asteroid, double &dt);

};

#endif
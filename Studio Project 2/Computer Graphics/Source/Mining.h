#ifndef _MINING_H
#define _MINING_H
/****************************************************************************/
/*!
\file Mining.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "Asteroid.h"
#include "PlayerShip.h"
#include "Collision.h"
/******************************************************************************/
/*!
		Class Mining:
\brief	
*/
/******************************************************************************/
struct Mining {

public:
	static void Mine(PlayerShip* playerShip, Asteroid* asteroid, double &dt);

};

#endif
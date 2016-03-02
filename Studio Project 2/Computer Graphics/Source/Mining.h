#ifndef _MINING_H
#define _MINING_H

#include "Asteroid.h"
#include "PlayerShip.h"
#include "Collision.h"

struct Mining {

public:
	static void Mine(PlayerShip* playerShip, Asteroid* asteroid, double &dt);

};

#endif
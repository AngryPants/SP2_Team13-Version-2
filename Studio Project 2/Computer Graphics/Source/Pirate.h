#ifndef _PIRATE_H
#define _PIRATE_H

#include "Ship.h"

class Pirate : public Ship {

public:
	Pirate();
	virtual ~Pirate();
	virtual void Die(Player &player);

};

#endif
#ifndef _OMBER_H
#define _OMBER_H

#include "Asteroid.h"

class Omber : public Asteroid {

public:
	//Constructor & Destructor
	Omber();
	~Omber();

	//Functions
	virtual void Die(Player &player);

};

#endif
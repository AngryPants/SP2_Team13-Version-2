#ifndef _KERNITE_H
#define _KERNITE_H

#include "Asteroid.h"

class Kernite : public Asteroid {

public:
	//Constructor & Destructor
	Kernite();
	~Kernite();

	//Functions
	virtual void Die(Player &player);

};

#endif
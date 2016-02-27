#ifndef _PLAYERHUMAN_H
#define _PLAYERHUMAN_H

#include "RigidBody.h"

class PlayerHuman : public RigidBody {

public:
	//Constructor & Destructor
	PlayerHuman(string);
	~PlayerHuman();

};

#endif
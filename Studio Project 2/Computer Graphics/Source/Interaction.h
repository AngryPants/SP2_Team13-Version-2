#ifndef _INTERACTION_H
#define _INTERACTION_H

#include "Interactable.h"

struct Interaction {

private:
	static string message;

public:
	//Constructor & Destructor
	Interaction();
	~Interaction();

	//Getters
	static string GetRenderMessage();

	//Functions
	static bool ShipToObject(Player &player, Interactable* object, double &dt);

};

#endif
#ifndef _INTERACTION_H
#define _INTERACTION_H
/*****************************************/
/*!
\file Interaction
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
struct to define Interactions
*/
/*****************************************/
#include "Interactable.h"
/*****************************************/
/*!
		Struct Interaction
\brief
Define Interaction and its method
*/
/*****************************************/
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
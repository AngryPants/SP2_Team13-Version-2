#ifndef _WARPGATE_H
#define _WARPGATE_H
/*****************************************/
/*!
\file WarpGate.h
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Header file for WarpGate
*/
/*****************************************/
#include"Interactable.h"
/*****************************************/
/*!
Class WarpGate
\brief
Define a WarpGate and its methods,child class of interactable
*/
/*****************************************/
class WarpGate : public Interactable {

private:
	Vector3 exitPosition;

public:
	//Constructors & Destructor
	WarpGate(string name, Vector3 position, Vector3 exitPosition);
	virtual ~WarpGate();
	
	//Functions
	virtual void Interact(Player &player, double &dt);

	//Getters
	Vector3 GetExitPosition();

	//Setters
	void SetExitPosition(Vector3 position);
	void SetExitPosition(float x, float y, float z);

};


#endif
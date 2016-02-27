#ifndef _WARPGATE_H
#define _WARPGATE_H

#include"Interactable.h"

class WarpGate : public Interactable
{
public:
	//Constructors & Destructor
	WarpGate(Vector3 exitPosition, float messageRadius, float interactRadius, string message, string name, string meshFile, const char* textureFile, Material material);
	virtual  ~WarpGate();
	//variable
	Vector3 exitPosition;
	//function
	virtual void Interact(RigidBody* object, double &dt);
	virtual void PlayAnimation(RigidBody* object, double &dt);

};


#endif
#ifndef _SPACESTATION_H
#define _SPACESTATION_H

#include"Interactable.h"

class SpaceStation : public Interactable {

private:
	unsigned int sceneNumber;

public:
	//Constructors & Destructor
	virtual void Interact(RigidBody* object,double &dt);
	virtual void PlayAnimation(RigidBody* object, double &dt);

	SpaceStation(float messageRadius, float interactRadius, string message, string name, string meshFile, const char* textureFile, Material material, unsigned int sceneNumber);
	virtual ~SpaceStation();

};

#endif
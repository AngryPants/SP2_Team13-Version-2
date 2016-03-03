#ifndef _SPACESTATION_H
#define _SPACESTATION_H
/*****************************************/
/*!
\file SpaceStation
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Creates a spacestation object
*/
/*****************************************/
#include"Interactable.h"
#include "Load.h"

/*****************************************/
/*!
		Class SpaceStation
\brief
Define a SpaceStation and its methods,child class of interactable
*/
/*****************************************/
class SpaceStation : public Interactable {

private:
	unsigned int sceneNumber;

public:
	//Constructors & Destructor
	SpaceStation(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material, unsigned int sceneNumber);
	virtual ~SpaceStation();

	//Functions
	virtual void Interact(Player &player,double &dt);
	virtual void PlayAnimation(Player &player, double &dt);

};

#endif
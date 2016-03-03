#ifndef _INTERACTABLE_H
#define _INTERACTABLE_H
/*****************************************/
/*!
\file Interactable
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Class to define an Interactable object
*/
/*****************************************/
#include "Application.h"
#include "SharedData.h"
#include "Player.h"
/*****************************************/
/*!
Class Interactable
\brief
Define a Interactable and its methods, child class of GameObject.
*/
/*****************************************/
class Interactable : public GameObject {

private:
	//Variables
	float approachRadius;
	float interactRadius;
	string approachMessage;
	string interactMessage;

protected:
	//Constructor
	Interactable(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material);

public:
	//Destructor
	virtual ~Interactable();
	
	//Functions
	virtual void Interact(Player &player, double &dt) = 0;
	virtual void PlayAnimation(Player &player, double &dt) = 0;

	//Getters
	string GetApproachMessage();
	string GetInteractMessage();
	float GetApproachRadius();
	float GetInteractRadius();

	//Setters
	void SetApproachMessage(string message);
	void SetInteractMessage(string message);
	void SetApproachRadius(float radius);
	void SetInteractRadius(float radius);

};


#endif
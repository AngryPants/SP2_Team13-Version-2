#ifndef _INTERACTABLE_H
#define _INTERACTABLE_H

#include"GameObject.h"
#include "Application.h"
#include "SharedData.h"
#include "RigidBody.h"

class Interactable : public GameObject {

private:
	//Variables
	float messageRadius;
	float interactRadius;
	string message;

protected:
	bool isInteracting;

	//Constructor
	Interactable(float messageRadius, float interactRadius, string message, string name, string meshFile, const char* textureFile, Material material);

public:
	//Destructor
	virtual ~Interactable();
	
	//Is-ter
	//bool isInteracting();

	//Getters
	string GetRenderMessage();
	float GetMessageRadius();
	float GetInteractRadius();
	bool GetInteracting();

	//Setters
	void SetRenderMessage(string message); //Make sure the radiuses are minimum 0.0f
	void SetMessageRadius(float radius); //Make sure the message radius > interact radius.
	void SetInteractRadius(float radius);
	void SetInteracting(bool interact);

	virtual void Interact(RigidBody * object, double &dt) {}
	virtual void PlayAnimation(RigidBody * object, double &dt) {}

};


#endif
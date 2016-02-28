#ifndef _WARPGATE_H
#define _WARPGATE_H

#include"Interactable.h"

class WarpGate : public Interactable {

private:
	Vector3 exitPosition;

public:
	//Constructors & Destructor
	WarpGate(string name, Vector3 exitPosition);
	virtual ~WarpGate();
	
	//Functions
	virtual void Interact(Player &player, double &dt);
	virtual void PlayAnimation(Player &player, double &dt);

	//Getters
	Vector3 GetExitPosition();

	//Setters
	void SetExitPosition(Vector3 position);
	void SetExitPosition(float x, float y, float z);

};


#endif
#ifndef _OUTERSPACE_H
#define _OUTERSPACE_H

#include "GameScene.h";
#include "Player.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "Asteroid.h"
#include "AI.h";
#include "Interactable.h"
#include "CarrickStation.h"
#include "Portal.h"

class OuterSpace : public GameScene {

public:
	//Constructor & Destructor
	OuterSpace();
	~OuterSpace();

	//GameObjects
	list<Ship*> enemies;
	list<Interactable*> iSpaceObjects;
	list<Asteroid*> asteroids;
	Player* player;

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void BoundCheck();
	void RenderObjects();
	bool warning;

};

#endif
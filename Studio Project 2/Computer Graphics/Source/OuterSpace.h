#ifndef _OUTERSPACE_H
#define _OUTERSPACE_H

#include "GameScene.h";
#include "Player.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "Asteroid.h"
#include "AI.h"
#include "Interactable.h"
#include "CarrickStation.h"
#include "Portal.h"
#include "Spawn.h"

class OuterSpace : public GameScene {

public:
	//Constructor & Destructor
	OuterSpace();
	~OuterSpace();

	//GameObjects
	list<Ship*> enemies;
	list<Interactable*> iSpaceObjects;
	list<Asteroid> asteroids;
	SpawnZone spawnZone1;
	Player* player;
	double frameTime;
	Vector3 zoneCenter;
	string nameCheck;

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void BoundsCheck();
	void RenderObjects();
	void UpdateSpaceInteractable(double &dt);
	bool warning;

};

#endif
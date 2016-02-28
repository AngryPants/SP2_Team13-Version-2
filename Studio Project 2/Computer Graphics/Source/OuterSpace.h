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
#include "Spawn.h"

class OuterSpace : public GameScene {

private:
	//Variables
	bool warning;
	string nameCheck;

	//GameObjects
	list<Ship> enemies;
	list<Interactable*> iSpaceObjects;
	list<Asteroid> asteroids;
	SpawnZone spawnZone1;
	Player* player;
	
	//Functions
	void BoundsCheck();
	void RenderObjects();
	void UpdateSpaceInteractable(double &dt);

public:
	//Constructor & Destructor
	OuterSpace();
	~OuterSpace();

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

};

#endif
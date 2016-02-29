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
#include "WarpGate.h"
#include "Spawn.h"
#include "Interaction.h"

class OuterSpace : public GameScene {

private:

	enum GEOMETRY
	{
		CROSSHAIR,
		MAXHEALTH,
		CURRHEALTH,
		END,
	};

	//Variables
	bool warning;
	string nameCheck;
	string message1;
	Mesh*meshList[END];

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
	void UpdateUserInterFace(double&dt);
	void UserInterFace();
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
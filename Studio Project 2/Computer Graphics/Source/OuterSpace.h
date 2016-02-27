#ifndef _OUTERSPACE_H
#define _OUTERSPACE_H

#include "GameScene.h";
#include "Player.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "Asteroid.h"
#include "AI.h";

class OuterSpace : public GameScene {

public:
	//Constructor & Destructor
	OuterSpace();
	~OuterSpace();

	//GameObjects
	list<Ship*> enemies;
	list<Asteroid*> asteroids;
	Player* player;
	double frameTime;

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

};

#endif
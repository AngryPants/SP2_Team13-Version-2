#ifndef _OUTERSPACE_H
#define _OUTERSPACE_H

#include "GameScene.h";
#include "Player.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "Asteroid.h"
#include "AI.h"
#include "Mining.h"
#include "CarrickStation.h"
#include "WarpGate.h"
#include "Spawn.h"
#include "Interaction.h"

class OuterSpace : public GameScene {

private:
	enum KEYPRESS
	{
		UP,
		DOWN,
		RETURN,
		NONE,
	};

	enum MENU
	{
		RESTART,
		SOUND,
		QUIT,
		THE_END,
	};

	enum GEOMETRY
	{
		CROSSHAIR,
		MAXHEALTH,
		CURRHEALTH,
		DISPLAY,
		TAB,
		END,
	};

	//Variables
	bool warning;
	string nameCheck;
	string message1;
	Mesh*meshList[END];
	MENU menuOption;
	bool isPressed[NONE];
	bool pause;
	
	//Functions
	void BoundsCheck();
	void RenderAsteroids(SpawnZone spawnZone);
	void RenderEnemy(SpawnZone spawnZone);
	void UpdateSpaceInteractable(double &dt);
	void UpdateUserInterFace(double&dt);
	void RenderFlightHUD();
	void UpdateStartMenu();
	void CheckKeyPress();
	void RenderStartMenu();
	void DeathCheck();
	void UpdateDeathScreen();
	void RenderDeathScreen();

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
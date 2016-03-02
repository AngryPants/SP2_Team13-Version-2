#ifndef _HANGAR_H
#define _HANGAR_H

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
#include "Upgrade.h"

class Hangar : public GameScene {

private:
	enum KEYPRESS
	{
		UP,
		DOWN,
		BACK,
		RETURN,
		E,
		S,
		NONE,
	};

	enum MENU
	{
		START,
		SOUND,
		QUIT,
		THE_END,
	};

	enum GEOMETRY
	{
		HANGAR,
		DECO_SHIP_RED,
		DECO_SHIP_BLUE,
		DECO_TRUCK,
		
		NPC_HEAD,
		NPC_LEFT_HAND,
		NPC_RIGHT_HAND,
		NPC_BODY,
		NPC_LEFT_LEG,
		NPC_RIGHT_LEG,

		VELDSPAR,
		OMBER,
		KERNITE,

		END,
	};

	//Variables
	bool warning;
	string nameCheck;
	string message1;
	Mesh*meshList[END];
	MENU menuOption;
	bool isPressed[NONE];
	bool pause,Leave,Shop;
	int spinObj;
	//GameObjects
	list<Ship> enemies;
	list<Interactable*> iSpaceObjects;
	list<Asteroid> asteroids;
	SpawnZone spawnZone1;
	Player* player;

	//Functions
	void BoundsCheck(Vector3 position);
	void RenderObjects();
	void UpdateStartMenu();
	void CheckKeyPress();
	void RenderStartMenu();
	void LeavingAnimation(double &dt);
	void RenderUI();
public:
	//Constructor & Destructor
	Hangar();
	~Hangar();

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

};

#endif
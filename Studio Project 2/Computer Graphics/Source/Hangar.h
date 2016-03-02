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
	enum MENU
	{
		START,
		SOUND,
		QUIT,
		THE_END,l
	};

	//Variables
	MENU menuOption;
	bool Leave,codex;
	float spinObj;
	int random;

	//GameObjects
	Player* player;

	//Functions
	void RenderObjects();
	void UpdateStartMenu();
	void RenderStartMenu();
	void LeavingAnimation(double &dt);
	void RenderUI();
	void RenderNPC();

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
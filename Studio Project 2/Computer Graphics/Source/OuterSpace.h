#ifndef _OUTERSPACE_H
#define _OUTERSPACE_H
/****************************************************************************/
/*!
\file OuterSpace.h
\author
\par email:
\brief

*/
/****************************************************************************/
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
#include "Load.h"
/******************************************************************************/
/*!
		Class OuterSpace:
\brief
*/
/******************************************************************************/
class OuterSpace : public GameScene {

private:

	enum MENU
	{
		RESTART,
		QUIT,
		THE_END,
	};

	//Variables
	bool warning;
	MENU menuOption;
	
	//Functions
	void BoundsCheck();
	void RenderAsteroids(SpawnZone spawnZone);
	void RenderEnemy(SpawnZone spawnZone);
	void UpdateSpaceInteractable(double &dt);
	void UpdateUserInterFace(double&dt);
	void RenderFlightHUD();
	void UpdateStartMenu();
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
#ifndef _PLAYER_H
#define _PLAYER_H
/****************************************************************************/
/*!
\file Player.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include <string>
#include "Quest.h"
#include <list>
#include "PlayerShip.h"
#include "PlayerHuman.h"

using std::list;
using std::string;
/******************************************************************************/
/*!
		Struct Player:
\brief
*/
/******************************************************************************/
enum PLAYER_STATE {

	MAIN_MENU = 0,
	ANIMATING,
	PLAYING,
	DEAD,
	NUM_PLAYER_STATE,

};

struct Player {

private:
	string name;
	Inventory inventory;
	list<Quest> quests;
	PlayerShip ship;
	PlayerHuman human;
	PLAYER_STATE playerState;
	bool godMode;

public:
	//Constructor & Destructor
	Player(string name, string questFile, string inventoryFile, string shipFile);
	~Player();

	//Getters
	string GetName();
	Inventory* GetInventory();
	list<Quest>* GetQuests();
	PlayerShip* GetShip();
	PlayerHuman* GetHuman();
	PLAYER_STATE GetState();
	bool GodModeOn();

	//Setters
	void SetState(PLAYER_STATE playerState);
	void SetGodMode(bool mode);

};

#endif
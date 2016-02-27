#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "Inventory.h"
#include "Quest.h"
#include <list>
#include "PlayerShip.h"
#include "PlayerHuman.h"
#include "Load.h"

using std::list;
using std::string;

struct Player {

private:
	string name;
	Inventory inventory;
	list<Quest> quests;
	PlayerShip ship;
	PlayerHuman human;

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

};

#endif
#ifndef _LOADFILE_H
#define _LOADFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "Inventory.h"
#include "PlayerShip.h"
#include "Quest.h"

using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;

struct Load {

public:
	Load();
	~Load();

	static void LoadInventory(Inventory &inventory, string filePath);
	static void LoadShip(PlayerShip &ship, string filePath);
	static void LoadQuest(list<Quest> &quest, string filePath);

};

#endif
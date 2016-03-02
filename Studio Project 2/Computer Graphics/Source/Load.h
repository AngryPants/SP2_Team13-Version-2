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
#include "Player.h"

using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;

struct Load {

public:
	Load();
	~Load();

	static void LoadFile(string FilePath, Player &player);
	static void SaveFile(string FilePath, Player &player);

};

#endif
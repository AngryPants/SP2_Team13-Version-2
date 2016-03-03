#ifndef _LOADFILE_H
#define _LOADFILE_H
/****************************************************************************/
/*!
\file Load.h
\author
\par email:
\brief
Struct that Loads information and details from text files
*/
/****************************************************************************/
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
/*****************************************/
/*!
		Struct Load
\brief

*/
/*****************************************/
struct Load {

public:
	Load();
	~Load();

	static void LoadFile(string FilePath, Player &player);
	static void SaveFile(string FilePath, Player &player);
	static void ResetFile(string FilePath, Player &player, string ResetFile);

};

#endif
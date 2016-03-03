#ifndef _UPGRADE_H
#define _UPGRADE_H
/****************************************************************************/
/*!
\file Upgrade.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include <string>
#include "Mesh.h"

using std::string;
/******************************************************************************/
/*!
		Class Upgrade:
\brief
*/
/******************************************************************************/
class Upgrade {

public:

	enum UPGRADE_TYPE {
	
		WEAPON,
		ARMOUR,
		ENGINE,
		NUM_UPGRADE,

	};

	string name;
	string seller;
	string description;

	UPGRADE_TYPE upgradeType;

	int cost;
	
	int fireRate;
	int damage;
	
	int armour;
	
	int speed;
	int fuel;

	Mesh* mesh;

	Upgrade();
	~Upgrade();

};

#endif
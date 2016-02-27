#ifndef _UPGRADE_H
#define _UPGRADE_H

#include <string>
#include "Mesh.h"

using std::string;

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
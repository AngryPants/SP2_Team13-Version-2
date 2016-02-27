#include "Upgrade.h"

Upgrade::Upgrade() {
	
	name = "<Upgrade Name>";
	description = "<Upgrade Description>";
	seller = "<Seller Name>";
	upgradeType = WEAPON,
	fireRate = 3;
	damage = 0;
	speed = 0;
	fuel = 0;
	armour = 0;
	cost = 0;
	mesh = nullptr;

}

Upgrade::~Upgrade() {
}
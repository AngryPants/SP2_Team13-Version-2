#include "Player.h"

//Constructor
Player::Player(string name, string questFile, string inventoryFile, string shipFile) 
: human(name) {

	this->name = name;
	Load::LoadQuest(quests, questFile);
	Load::LoadInventory(inventory, inventoryFile);
	Load::LoadShip(ship, shipFile);

}

//Destructor
Player::~Player() {
}

//Getters
string Player::GetName() {

	return this->name;

}

Inventory* Player::GetInventory() {

	return &(this->inventory);

}

list<Quest>* Player::GetQuests() {

	return &(this->quests);

}

PlayerShip* Player::GetShip() {

	return &(this->ship);

}

PlayerHuman* Player::GetHuman() {

	return &(this->human);

}
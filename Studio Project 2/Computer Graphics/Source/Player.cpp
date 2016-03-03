#include "Player.h"

//Constructor
Player::Player(string name, string questFile, string inventoryFile, string shipFile) 
: human(name) {

	this->name = name;
	SetGodMode(false);

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

PLAYER_STATE Player::GetState() {

	return this->playerState;

}

bool Player::GodModeOn() {

	return this->godMode;

}

//Setters
void Player::SetState(PLAYER_STATE playerState) {

	this->playerState = playerState;

}

void Player::SetGodMode(bool mode) {

	this->godMode = mode;

}
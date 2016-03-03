#include "Load.h"

Load::Load() {
}

Load::~Load() {
}

void Load::SaveFile(string filePath, Player &player)
{
	std::fstream fileStream;

	fileStream.open(filePath, std::ofstream::out | std::ofstream::trunc);

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open and save into " << filePath << ". Are you in the right directory?\n";
		return;

	}

	fileStream.close();

	fileStream.open(filePath, std::fstream::in | std::fstream::out);

	string name;
	string state;
	string gold;
	string armour;
	string veldspar;
	string omber;
	string kernite;

	name = "Name " + player.GetName();
	state = "State " + (std::to_string(player.GetState()));
	gold = "Gold " + (std::to_string(player.GetInventory()->GetGold()));
	armour = "Armour " + (std::to_string(player.GetShip()->GetMaxHealth()));

	fileStream << name << endl;
	fileStream << state << endl;
	fileStream << gold << endl;
	fileStream << armour << endl;

	for (map<Item, int>::iterator iter = player.GetInventory()->GetItems()->begin(); iter != player.GetInventory()->GetItems()->end(); ++iter) {

		fileStream << iter->first.GetName() + " " + std::to_string(iter->second) << endl;

	}

	fileStream << "End";

	fileStream.close();

}

void Load::LoadFile(string filePath, Player &player, Inventory &inventory, PlayerShip &playerShip)
{

	std::fstream fileStream;
	fileStream.open(filePath, std::fstream::in | std::fstream::out);

	//PLAYER_STATE state;
	int state = 0 ;
	int gold = 0;
	//int *test = &gold;
	int armour;
	int veldspar;
	int omber;
	int kernite;
	
	while (!fileStream.eof()) {

		char buf[256];

		fileStream.getline(buf, 256);

		if (strncmp("Name ", buf, 5) == 0) { //process vertex position

			sscanf_s((buf + 5), "%d", (&player.GetName()));

		}
		else if (strncmp("State ", buf, 6) == 0) {

			sscanf_s((buf + 6), "%d", &state);
			if (state == 0)
			{
				player.SetState(MAIN_MENU);
			}
			if (state == 1)
			{
				player.SetState(ANIMATING);
			}
			if (state == 2)
			{
				player.SetState(PLAYING);
			}
			if (state == 3)
			{
				player.SetState(DEAD);
			}

		}
		else if (strncmp("Gold ", buf, 5) == 0) {

			sscanf_s((buf + 5), "%d", &gold);
			player.GetInventory()->SetGold(gold);

		}
		else if (strncmp("Armour ", buf, 7) == 0) {

			sscanf_s((buf + 7), "%d", &armour);
			player.GetShip()->SetMaxHealth(armour);
			
		}
		else if (strncmp("Copper ", buf, 7) == 0) {

			sscanf_s((buf + 7), "%d", &veldspar);
			player.GetInventory()->AddItem(Item("Copper", 3, 1), veldspar);

		}
		else if (strncmp("Steel ", buf, 6) == 0) {

			sscanf_s((buf + 6), "%d", &omber);
			player.GetInventory()->AddItem(Item("Steel", 8, 2), omber);

		}
		else if (strncmp("Tin ", buf, 4) == 0) {

			sscanf_s((buf + 4), "%d", &kernite);
			player.GetInventory()->AddItem(Item("Tin", 20, 3), kernite);

		}
		else if (strncmp("End", buf, 3) == 0) {}

	}
	fileStream.close();
}
#include "Load.h"
/****************************************************************************/
/*!
\brief
Constructor of the Class Load
*/
/****************************************************************************/
Load::Load() {
}
/****************************************************************************/
/*!
\brief
Destructor of the Class Load
*/
/****************************************************************************/
Load::~Load() {
}
/****************************************************************************/
/*!
\brief
Saves the player's progress onto a text file
\param filePath
A string value that defines the filePath of the file to be loaded
\param player
A reference of the Class Player
*/
/****************************************************************************/
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

		fileStream << iter->first.GetName() + " " + std::to_string(iter->first.GetID()) + " " + std::to_string(iter->second) << endl;

	}

	fileStream << "End";

	fileStream.close();

}
/****************************************************************************/
/*!
\brief
Read from a text file and stores the data into a Player Class
\param filePath
A string that defines the filePath of the text file
\param player
A reference to the Class Player
*/
/****************************************************************************/
void Load::LoadFile(string filePath, Player &player)
{

	std::fstream fileStream;
	fileStream.open(filePath, std::fstream::in | std::fstream::out);

	int state = 0 ;
	int gold = 0;
	int armour;
	int veldspar;
	int veldsparID;
	int omber;
	int omberID;
	int kernite;
	int kerniteID;
	
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

			sscanf_s((buf + 7), "%d", &veldsparID);
			sscanf_s((buf + 9), "%d", &veldspar);
			player.GetInventory()->AddItem(Item("Copper", 3, veldsparID), veldspar);

		}
		else if (strncmp("Steel ", buf, 6) == 0) {

			sscanf_s((buf + 6), "%d", &omberID);
			sscanf_s((buf + 8), "%d", &omber);
			player.GetInventory()->AddItem(Item("Steel", 8, omberID), omber);

		}
		else if (strncmp("Tin ", buf, 4) == 0) {

			sscanf_s((buf + 4), "%d", &kerniteID);
			sscanf_s((buf + 6), "%d", &kernite);
			player.GetInventory()->AddItem(Item("Tin", 20, kerniteID), kernite);

		}
		else if (strncmp("End", buf, 3) == 0) {}

	}
	fileStream.close();
}
/****************************************************************************/
/*!
\brief
Transfer data from a text file to another to reset the player's progress
\param filePath
A string that defines the filePath of the text file
\param resetFile
A string that defines the filePath of the resetting text file
*/
/****************************************************************************/
void Load::ResetFile(string filePath, Player &player, string resetFile)
{
	std::ifstream fileStream;
	std::fstream resetFileStream;

	LoadFile(resetFile, player);
	player.GetInventory()->DecreaseItem(Item("Copper", 3, 1), (player.GetInventory()->GetNumberOf(Item("Copper", 3, 1))));
	player.GetInventory()->DecreaseItem(Item("Steel", 8, 2), (player.GetInventory()->GetNumberOf(Item("Steel", 8, 2))));
	player.GetInventory()->DecreaseItem(Item("Tin", 20, 3), (player.GetInventory()->GetNumberOf(Item("Tin", 20, 3))));
	SaveFile(filePath, player);

}
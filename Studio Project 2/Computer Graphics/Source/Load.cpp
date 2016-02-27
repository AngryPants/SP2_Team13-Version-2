#include "Load.h"

Load::Load() {
}

Load::~Load() {
}

void Load::LoadInventory(Inventory &inventory, string filePath) {

}

void Load::LoadShip(PlayerShip &ship, string filePath) {

}

void Load::LoadQuest(list<Quest> &quest, string filePath) {

}

/*bool LoadInventory(string filePath) {

	std::ifstream fileStream(filePath, std::ios::binary);

	if (!fileStream.is_open()) {
	
		cout << "Unable to open " << filePath << ". Are you in the right directory?" << endl;

		return false;

	}

	while (!fileStream.eof()) {

		char buf[256];

		fileStream.getline(buf, 256);

		if (strncmp("Gold ", buf, 5) == 0) {
			
			sscanf_s((buf + 5), "%d", &Inventory::GetInstance()->gold);

		} else if (strncmp("Fuel ", buf, 5) == 0) {
		
			sscanf_s((buf + 5), "%d", &Inventory::GetInstance()->fuel);

		} else if (strncmp("Veldspar ", buf, 9) == 0) {
		
			sscanf_s((buf + 9), "%d", &Inventory::GetInstance()->veldspar);

		} else if (strncmp("Omber ", buf, 6) == 0) {
		
			sscanf_s((buf + 6), "%d", &Inventory::GetInstance()->omber);

		} else if (strncmp("Kernite ", buf, 6) == 0) {
		
			sscanf_s((buf + 6), "%d", &Inventory::GetInstance()->kernite);

		}

	}

	fileStream.close();

	return true;

}

bool LoadQuests(string filePath, list<Quest> &quests) {

	std::ifstream fileStream(filePath, std::ios::binary);

	if(!fileStream.is_open()) {

		std::cout << "Unable to open " << filePath << ". Are you in the right directory?" << endl;
		return false;

	}

	Quest quest;

	while (!fileStream.eof()) {
		
		char buf[256];

		fileStream.getline(buf, 256);
		
		if (strncmp("ConditionID ", buf, 12) == 0) {
			
			sscanf_s((buf + 12), "%d", &quest.conditionID);

		} else if (strncmp("Reward ", buf, 7) == 0) {
		
			sscanf_s((buf + 7), "%d", &quest.reward);

		} else if (strncmp("Current ", buf, 8) == 0) {
		
			sscanf_s((buf + 8), "%d", &quest.current);

		} else if (strncmp("Target ", buf, 7) == 0) {
		
			sscanf_s((buf + 7), "%d", &quest.target);

		} else if (strncmp("Active ", buf, 7) == 0) {
		
			sscanf_s((buf + 7), "%d", &quest.isActive);

		} else if (strncmp("Complete ", buf, 9) == 0) {
		
			sscanf_s((buf + 9), "%d", &quest.isComplete);

		} else if (strncmp("Name ", buf, 5) == 0) {
		
			string str = "";

			for (int i = 5; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			 quest.name = str;

		} else if (strncmp("Giver ", buf, 6) == 0) {
		
			string str = "";

			for (int i = 6; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			quest.giver = str;

		} else if (strncmp("Desc ", buf, 5) == 0) {

			string str = "";

			for (int i = 5; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			quest.description = str;

		} else if (strncmp("End", buf, 3) == 0) {
		
			if (quest.isActive) {
			
				quests.push_front(quest);

			} else {
			
				quests.push_back(quest);

			}

		}

	} 

	fileStream.close(); // close file

	return true;

}

bool LoadShop(string filePath, list<Upgrade> &upgrades) {

	std::ifstream fileStream(filePath, std::ios::binary);

	if(!fileStream.is_open()) {

		std::cout << "Unable to open " << filePath << ". Are you in the right directory?\n";
		return false;

	}

	Upgrade upgrade;

	while (!fileStream.eof()) {
		
		char buf[256];

		fileStream.getline(buf, 256);
		
		if (strncmp("Type ", buf, 5) == 0) {

			string str = "";

			for (int i = 5; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			if (str == "Weapon") {
			
				upgrade.upgradeType = Upgrade::WEAPON;
				
			} else if (str == "Armour") {
			
				upgrade.upgradeType = Upgrade::ARMOUR;

			} else if (str == "Engine") {
			
				upgrade.upgradeType = Upgrade::ENGINE;

			}

		} else if (strncmp("Name ", buf, 5) == 0) {
		
			string str = "";

			for (int i = 5; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			upgrade.name = str;

		} else if (strncmp("Desc ", buf, 5) == 0) {
		
			string str = "";

			for (int i = 5; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			upgrade.description = str;

		} else if (strncmp("Seller ", buf, 7) == 0) {
		
			string str = "";

			for (int i = 7; buf[i] != '\r'; ++i) {
			
				str += buf[i];

			}

			upgrade.seller = str;

		} else if (strncmp("Cost ", buf, 5) == 0) {
		
			sscanf_s((buf + 5), "%d", &upgrade.cost);

		} else if (strncmp("Fire Rate ", buf, 9) == 0) {
		
			sscanf_s((buf + 9), "%d", &upgrade.fireRate);

		} else if (strncmp("Damage ", buf, 7) == 0) {
		
			sscanf_s((buf + 7), "%d", &upgrade.damage);

		} else if (strncmp("Speed ", buf, 6) == 0) {
		
			sscanf_s((buf + 6), "%d", &upgrade.speed);

		} else if (strncmp("Fuel ", buf, 5) == 0) {
		
			sscanf_s((buf + 5), "%d", &upgrade.fuel);

		} else if (strncmp("Armour ", buf, 7) == 0) {
		
			sscanf_s((buf + 7), "%d", &upgrade.armour);

		} else if (strncmp("End", buf, 3) == 0) {
		
			upgrades.push_back(upgrade);

		}

	} 

	fileStream.close(); // close file

	return true;

}


bool loadsave(string filePath)
{
	std::ifstream fileStream(filePath, std::ios::binary);

	

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open " << filePath << ". Are you in the right directory?\n";
		return false;

	}

	//SharedData Data;

	while (!fileStream.eof()) {

		char buf[256];

		fileStream.getline(buf, 256);

		if (strncmp("Health ", buf, 7) == 0) { //process vertex position

			float health;

			sscanf_s((buf + 7), "%d", &health);

			PlayerShip::GetInstance()->SetHealth(health);

		}
		else if (strncmp("Gold ", buf, 5) == 0) {

			sscanf_s((buf + 5), "%d", &Inventory::GetInstance()->gold);
		
		}
		else if (strncmp("Fuel ", buf, 5) == 0) {

			sscanf_s((buf + 5), "%d", &Inventory::GetInstance()->fuel);

		}
		else if (strncmp("Veldspar ", buf, 9) == 0) {

			sscanf_s((buf + 9), "%d", &Inventory::GetInstance()->veldspar);

		}
		else if (strncmp("Omber ", buf, 6) == 0) {

			sscanf_s((buf + 6), "%d", &Inventory::GetInstance()->omber);

		}
		else if (strncmp("Kernite ", buf, 8) == 0) {

			sscanf_s((buf + 8), "%d", &Inventory::GetInstance()->kernite);

		}
		else if (strncmp("End", buf, 3) == 0) {	}

	}
	fileStream.close();

	return true;
}
bool Save(string filePathStats, string filePathQuest, string filePathUpgrade, string filePathUpgradeTest)
{
	std::fstream fileStream;

	fileStream.open(filePathStats, std::ofstream::out | std::ofstream::trunc);

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open and save into " << filePathStats << ". Are you in the right directory?\n";
		return false;

	}

	fileStream.close();
	fileStream.open(filePathStats, std::fstream::in | std::fstream::out);



	string health = "Armour " + (std::to_string(PlayerShip::GetInstance()->GetHealth()));
	string gold = "Gold " + (std::to_string(Inventory::GetInstance()->gold));
	string fuel = "Fuel " + (std::to_string(Inventory::GetInstance()->fuel));
	
	string veldspar = "Veldspar " + (std::to_string(Inventory::GetInstance()->veldspar));
	string omber = "Omber " + (std::to_string(Inventory::GetInstance()->omber));
	string kernite = "Kernite " + (std::to_string(Inventory::GetInstance()->kernite));
	
	fileStream << health << endl;
	fileStream << gold << endl;
	fileStream << fuel << endl;
	fileStream << veldspar << endl;
	fileStream << omber << endl;
	fileStream << kernite << endl;

	fileStream << "End" << endl;

	fileStream.close();

	
	fileStream.open(filePathQuest, std::ofstream::out | std::ofstream::trunc);

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open and save into " << filePathQuest << ". Are you in the right directory?\n";
		return false;

	}

	fileStream.close();
	
	fileStream.open(filePathQuest, std::fstream::in | std::fstream::out);

	for (list<Quest>::iterator iter = QuestSystem::GetInstance()->quests.begin(); iter != QuestSystem::GetInstance()->quests.end(); ++iter)
	{
		string name = "Name " + (iter->name);
		string desc = "Desc " + (iter->description);
		string giver = "Giver " + (iter->giver);

		string id = "ConditionID " + (std::to_string(iter->conditionID));
		string current = "Current " + (std::to_string(iter->current));
		string target = "Target " + (std::to_string(iter->target));

		string active = "Active " + (std::to_string(iter->isActive));
		string complete = "Complete " + (std::to_string(iter->isComplete));
		string reward = "Reward " + (std::to_string(iter->reward));

		fileStream << name << endl;
		fileStream << desc << endl;
		fileStream << giver << endl;
		fileStream << id << endl;
		fileStream << current << endl;
		fileStream << target << endl;
		fileStream << active << endl;
		fileStream << complete << endl;
		fileStream << reward << endl;
		fileStream << "End" << endl;
		fileStream << "" << endl;
	}

	fileStream.close();

	fileStream.open(filePathUpgradeTest, std::ofstream::out | std::ofstream::trunc);

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open and save into " << filePathUpgrade << ". Are you in the right directory?\n";
		return false;

	}

	fileStream.close();

	fileStream.open(filePathUpgradeTest, std::fstream::in | std::fstream::out);

	string name;
	string type;
	string desc;
	string seller;
	string cost;
	string extra;
	string ending;

	if (PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON] != nullptr)
	{
		name = "Name " + PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->name;
		type = "Type Weapon";
		desc = "Desc " + PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->description;
		seller = "Seller " + PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->seller;
		cost = "Cost " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->cost);
		extra = "Fire Rate " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->fireRate) + "\nDamage " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->damage);
		ending = "END";

		fileStream << name << endl;
		fileStream << type << endl;
		fileStream << desc << endl;
		fileStream << seller << endl;
		fileStream << cost << endl;
		fileStream << extra << endl;
		fileStream << ending << endl;
		fileStream << "" << endl;
	}
	if (PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR] != nullptr)
	{
		name = "Name " + PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->name;
		type = "Type Armour";
		desc = "Desc " + PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->description;
		seller = "Seller " + PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->seller;
		cost = "Cost " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->cost);
		extra = "Armour " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->armour);
		ending = "END";

		fileStream << name << endl;
		fileStream << type << endl;
		fileStream << desc << endl;
		fileStream << seller << endl;
		fileStream << cost << endl;
		fileStream << extra << endl;
		fileStream << ending << endl;
		fileStream << "" << endl;
	}
	if (PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE] != nullptr)
	{
		name = "Name " + PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->name;
		type = "Type Engine";
		desc = "Desc " + PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->description;
		seller = "Seller " + PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->seller;
		cost = "Cost " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->cost);
		extra = "Speed " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->speed) + "\nFuel " + std::to_string(PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->fuel);
		ending = "END";

		fileStream << name << endl;
		fileStream << type << endl;
		fileStream << desc << endl;
		fileStream << seller << endl;
		fileStream << cost << endl;
		fileStream << extra << endl;
		fileStream << ending << endl;
		fileStream << "" << endl;
	}


	
	fileStream.close();

	return true;
}
bool Loadsave(string filePath)
{
	/*
	std::ifstream fileStream(filePath, std::ios::binary);

	

	if (!fileStream.is_open()) {

		std::cout << "Impossible to open " << filePath << ". Are you in the right directory?\n";
		return false;

	}

	//SharedData Data;

	while (!fileStream.eof()) {

		char buf[256];

		fileStream.getline(buf, 256);

		if (strncmp("Health ", buf, 7) == 0) { //process vertex position

			sscanf_s((buf + 7), "%d", &SharedData::GetInstance()->playerHealth);

		}
		else if (strncmp("Gold ", buf, 5) == 0) {

			sscanf_s((buf + 5), "%d", &SharedData::GetInstance()->gold);
		
		}
		else if (strncmp("Fuel ", buf, 5) == 0) {

			sscanf_s((buf + 5), "%d", &SharedData::GetInstance()->fuel);

		}
		else if (strncmp("Veldspar ", buf, 9) == 0) {

			sscanf_s((buf + 9), "%d", &SharedData::GetInstance()->veldspar);

		}
		else if (strncmp("Omber ", buf, 6) == 0) {

			sscanf_s((buf + 6), "%d", &SharedData::GetInstance()->omber);

		}
		else if (strncmp("Kernite ", buf, 8) == 0) {

			sscanf_s((buf + 8), "%d", &SharedData::GetInstance()->kernite);

		}
		else if (strncmp("Drones ", buf, 7) == 0) {

			sscanf_s((buf + 7), "%d", &SharedData::GetInstance()->drones);

		}
		else if (strncmp("Pirates ", buf, 8) == 0) {

			sscanf_s((buf + 8), "%d", &SharedData::GetInstance()->pirates);

		}
		else if (strncmp("Aliens ", buf, 7) == 0) {
			
			sscanf_s((buf + 7), "%d", &SharedData::GetInstance()->aliens);

		}
		else if (strncmp("End", buf, 3) == 0) {	}

	}
	fileStream.close();
	
	return true;
}*/
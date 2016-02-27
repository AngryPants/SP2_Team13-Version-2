#ifndef _INVENTORY_H
#define _INVENTORY_H

class Inventory {

private:
	int gold;
	int veldspar;
	int omber;
	int kernite;

public:
	//Constructor & Destructor
	Inventory();
	~Inventory();

	//Functions
	void AddGold(int gold);
	void AddVeldspar(int veldspar);
	void AddOmber(int omber);
	void AddKernite(int kernite);
	bool DecreaseGold(int gold);
	bool DecreaseVeldspar(int veldspar);
	bool DecreaseOmber(int omber);
	bool DecreaseKernite(int kernite);

	//Getters
	int GetGold();
	int GetVeldspar();
	int GetOmber();
	int GetKernite();

	//Setters
	void SetGold(int gold);
	void SetVeldspar(int veldspar);
	void SetOmber(int omber);
	void SetKernite(int kernite);

};

#endif
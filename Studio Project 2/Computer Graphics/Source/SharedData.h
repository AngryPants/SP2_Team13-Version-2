#ifndef _SHAREDDATA_H
#define _SHAREDDATA_H

class SharedData {

public:
	static SharedData* GetInstance();
	~SharedData();

	int sceneNumber;
	bool soundOn;
	bool quitGame;

private:
	SharedData();

};

#endif
#include "SharedData.h"

SharedData::SharedData() {

	sceneNumber = 2;
	soundOn = true;
	quitGame = false;

}

SharedData::~SharedData() {
}

SharedData* SharedData::GetInstance() {

	static SharedData sharedData;

	return &sharedData;

}
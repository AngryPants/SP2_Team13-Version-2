#include "SharedData.h"
/****************************************************************************/
/*!
\brief
Constructor of sharedData
*/
/****************************************************************************/
SharedData::SharedData() {

	sceneNumber = 1;
	soundOn = true;
	quitGame = false;

}
/****************************************************************************/
/*!
\brief
Destructor of sharedData
*/
/****************************************************************************/
SharedData::~SharedData() {
}
/****************************************************************************/
/*!
\brief
Create an instance for other places to access the value
*/
/****************************************************************************/
SharedData* SharedData::GetInstance() {

	static SharedData sharedData;

	return &sharedData;

}
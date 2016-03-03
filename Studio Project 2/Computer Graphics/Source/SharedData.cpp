/****************************************************************************/
/*!
\file SharedData.cpp
\author Terry
\par email: lnxTerry@gmail.com
\brief
CPP file for SharedData
*/
/****************************************************************************/
#include "SharedData.h"
/*****************************************/
/*!
\file SharedData.cpp
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Data that is being shared 
*/
/*****************************************/

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
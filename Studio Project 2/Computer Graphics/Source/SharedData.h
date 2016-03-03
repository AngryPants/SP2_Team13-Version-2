#ifndef _SHAREDDATA_H
#define _SHAREDDATA_H
/****************************************************************************/
/*!
\file SharedData.h
\author Terry
\par email: lnxTerry@gmail.com
\brief
Header file for SharedData
*/
/****************************************************************************/
/******************************************************************************/
/*!
		Class SharedData:
\brief

Class to define an SharedData, a singleton used to store global variables.
*/
/******************************************************************************/
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
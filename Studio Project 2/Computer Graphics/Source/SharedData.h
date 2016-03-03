#ifndef _SHAREDDATA_H
#define _SHAREDDATA_H
/****************************************************************************/
/*!
\file SharedData.h
\author Terry
\par email: lnxTerry@gmail.com
\brief
Singleton for every files using it
*/
/****************************************************************************/
/******************************************************************************/
/*!
		Class SharedData:
\brief

Class to define an SharedData
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
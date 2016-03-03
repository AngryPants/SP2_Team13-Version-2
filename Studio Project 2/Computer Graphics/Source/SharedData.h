#ifndef _SHAREDDATA_H
#define _SHAREDDATA_H
/****************************************************************************/
/*!
\file SharedData.h
\author
\par email:
\brief

*/
/****************************************************************************/
/******************************************************************************/
/*!
		Class SharedData:
\brief
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
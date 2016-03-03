#ifndef _HANGAR_H
#define _HANGAR_H
/*****************************************/
/*!
\file Hangar
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Class Hangar to Create Scene 1
*/
/*****************************************/
#include "GameScene.h";
#include "Player.h"
#include "SharedData.h"
#include "Load.h"
/*****************************************/
/*!
class Hangar
\brief
Define Hangar and its methods,Child class of GameScene
*/
/*****************************************/
class Hangar : public GameScene {

private:
	enum MENU
	{
		START,
		RESET,
		QUIT,
		THE_END,l
	};

	//Variables
	MENU menuOption;
	bool Leave,codex;
	float spinObj;
	int random;

	//GameObjects
	Player* player;

	//Functions
	void RenderObjects();
	void UpdateStartMenu();
	void RenderStartMenu();
	void LeavingAnimation(double &dt);
	void RenderUI();
	void RenderNPC();

public:
	//Constructor & Destructor
	Hangar();
	~Hangar();

	//Public Functions
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

};

#endif
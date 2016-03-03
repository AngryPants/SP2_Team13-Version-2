#ifndef _PLAYERCONTROL_H
#define _PLAYERCONTROL_H
/****************************************************************************/
/*!
\file PlayerControl.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for PlayerControl

*/
/****************************************************************************/
#include "MousePosition.h"
#include "PlayerShip.h"
#include "Camera.h"
#include "Application.h"
/******************************************************************************/
/*!
		Struct PlayerControl:
\brief
Defines the static functions for PlayerControl.

*/
/******************************************************************************/
struct PlayerControl {

	//Constructor & Destructor
	PlayerControl();
	~PlayerControl();

	static void RotateShip(Ship* ship, float maxTurningAngle, double &dt);
	static void MoveShip(PlayerShip* ship, float force, double &dt);
	static void Shoot(Ship* ship, Vector3 bulletPosition);

};

#endif
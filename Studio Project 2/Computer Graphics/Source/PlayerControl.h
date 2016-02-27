#ifndef _PLAYERCONTROL_H
#define _PLAYERCONTROL_H

#include "MousePosition.h"
#include "PlayerShip.h"
#include "Camera.h"
#include "Application.h"

struct PlayerControl {

	//Constructor & Destructor
	PlayerControl();
	~PlayerControl();

	static void RotateShip(Ship* ship, float maxTurningAngle, double &dt);
	static void MoveShip(PlayerShip* ship, float force, double &dt);
	static void Shoot(Ship* ship, Vector3 bulletPosition);
	//static void RotatePlayer();
	//static void MovePlayer();
	//static void RotateCameraX(Camera* camera);
	//static void RotateCameraY(Camera* camera);
	//static void RotateCameraZ(Camera* camera);

};

#endif
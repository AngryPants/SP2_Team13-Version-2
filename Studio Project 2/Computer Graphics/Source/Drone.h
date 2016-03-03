#ifndef _DRONE_H
#define _DRONE_H
/****************************************************************************/
/*!
\file Drone.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Drone

*/
/****************************************************************************/
#include "Ship.h"
/*****************************************/
/*!
		Class Drone
\brief
Defines
A Ship, just with the constructor parameters filled up.

*/
/*****************************************/
class Drone : public Ship {

public:
	//Constructor & Destructor
	Drone();
	virtual ~Drone();

};

#endif
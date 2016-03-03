#ifndef _CARRICKSTATION_H
#define _CARRICKSTATION_H
/*****************************************/
/*!
\file CarrickStation.h
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Header File for CarrickStation.
*/
/*****************************************/
#include "SpaceStation.h"
/*****************************************/
/*!
		Class CarrickStation
\brief
Defines a CarrickStation and its Methods,child class of SpaceStation
*/
/*****************************************/
class CarrickStation : public SpaceStation {

public:
	CarrickStation();
	virtual ~CarrickStation();

};

#endif
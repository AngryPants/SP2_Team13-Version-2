#ifndef _PIRATE_H
#define _PIRATE_H
/****************************************************************************/
/*!
\file Pirate.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Pirate

*/
/****************************************************************************/
#include "Ship.h"
/******************************************************************************/
/*!
		Class Pirate:
\brief
A Ship, just with the constructor parameters filled up.

*/
/******************************************************************************/
class Pirate : public Ship {

public:
	Pirate();
	virtual ~Pirate();

};

#endif
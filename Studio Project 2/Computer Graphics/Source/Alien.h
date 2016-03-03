#ifndef _ALIEN_H
#define _ALIEN_H
/****************************************************************************/
/*!
\file Alien.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Alien.

*/
/****************************************************************************/
#include "Ship.h"
/*****************************************/
/*!
		Class Alien
\brief
A Ship, just with the constructor parameters filled up.

*/
/*****************************************/

class Alien : public Ship {

public:
	//Constructor & Destructor
	Alien();
	virtual ~Alien();

};

#endif
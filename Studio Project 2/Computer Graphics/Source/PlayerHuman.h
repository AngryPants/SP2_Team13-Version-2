#ifndef _PLAYERHUMAN_H
#define _PLAYERHUMAN_H
/****************************************************************************/
/*!
\file PlayerHuman.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "RigidBody.h"
/******************************************************************************/
/*!
		Class PlayerHuman:
\brief
*/
/******************************************************************************/
class PlayerHuman : public RigidBody {

public:
	//Constructor & Destructor
	PlayerHuman(string);
	~PlayerHuman();

};

#endif
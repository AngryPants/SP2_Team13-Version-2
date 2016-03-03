#ifndef _MININGLASER_H
#define _MININGLASER_H
/****************************************************************************/
/*!
\file MiningLaser.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for MiningLaser.
*/
/****************************************************************************/
#include "GameObject.h"
/******************************************************************************/
/*!
		Class MiningLaser:
\brief
Defines MiningLaser, a child class of GameObject.

*/
/******************************************************************************/
class MiningLaser : public GameObject {

private:
	float length;
	float extractRate;
	float zRotation;

public:
	//Constructor & Destructor
	MiningLaser();
	~MiningLaser();

	void AddZRotation(float zRotation);

	//Getters
	float GetLength();
	float GetExtractRate();
	float GetZRotation();

	//Setters
	void SetLength(float length);

};

#endif
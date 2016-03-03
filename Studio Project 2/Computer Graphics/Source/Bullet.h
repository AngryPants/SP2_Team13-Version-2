#ifndef _BULLET_H
#define _BULLET_H
/****************************************************************************/
/*!
\file Bullet.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Bullet

*/
/****************************************************************************/
#include "GameObject.h"
/*****************************************/
/*!
		Class Bullet
\brief
Defines Bullet, a child class of GameObject.

*/
/*****************************************/

class Bullet : public GameObject {

private:
	float speed;
	int damage;
	double timeToDespawn;

public:
	//Constructors & Destructors
	Bullet(Vector3 position, Mtx44 rotationMatrix, int damage, const char* textureFile, float speed);
	Bullet(Vector3 position, Mtx44 rotationmatrix, int damage, const char* textureFile);
	~Bullet();

	//Functions
	void Update(double &dt);
	void UpdatePosition(double &dt);
	void Despawn();
	bool ShouldDelete();

	//Getters
	int GetDamage();
	float GetSpeed();

	//Setters
	void SetDamage(int damage);
	void SetSpeed(float speed);

};

#endif
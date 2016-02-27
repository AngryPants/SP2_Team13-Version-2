#ifndef _BULLET_H
#define _BULLET_H

#include "GameObject.h"

class Bullet : public GameObject {

private:
	bool removeBullet;
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
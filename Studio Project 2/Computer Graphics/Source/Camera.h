#ifndef CAMERA_H
#define CAMERA_H
/****************************************************************************/
/*!
\file Camera.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "SpaceObject.h"
/*****************************************/
/*!
		Class Camera
\brief

*/
/*****************************************/

class Camera {

private:
	Vector3 position;
	Vector3 target;
	Vector3 up;
	Vector3 view;
	Vector3 right;
	Mtx44 rotationMatrix;

public:
	//Constructor & Destructor
	Camera();
	~Camera();

	//Functions
	void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	void Reset();
	void Update(double dt);
	void FollowObject(SpaceObject* object, Vector3 offset);
	void UpdateXRotation(double &dt);
	void Rotate(Vector3 rotation);
	void Rotate(float x, float y, float z);

	//Setters
	void SetPosition(Vector3 position);
	void SetPosition(float x, float y, float z);
	void SetToRotation(Vector3 rotation);
	void SetToRotation(float x, float y, float z);
	void SetTarget(Vector3 target);
	void SetTarget(float x, float y, float z);

	//Getter
	Vector3 GetPosition();
	Vector3 GetTarget();
	Vector3 GetUp();
	Vector3 GetView();
	Vector3 GetRight();
	Mtx44 GetRotationMatrix();

};

#endif
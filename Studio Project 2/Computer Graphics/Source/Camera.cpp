#include "Camera.h"
#include "Application.h"

/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera::Camera()
{
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera::~Camera()
{
}

/******************************************************************************/
/*!
\brief
Initialize camera

\param pos - position of camera
\param target - where the camera is looking at
\param up - up vector of camera
*/
/******************************************************************************/
void Camera::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	
	this->position = pos;
	this->target = target;
	this->up = up;
	this->view = target - position;
	this->right = target.Cross(up).Normalized();

}

/******************************************************************************/
/*!
\brief
Reset the camera settings
*/
/******************************************************************************/
void Camera::Reset()
{
}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera::Update(double dt) {

}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation to follow an object.

\param object - Object to be followed
\param offset - the object of the camera to the object.
*/
/******************************************************************************/
void Camera::FollowObject(SpaceObject* object, Vector3 offset) {

	MS cameraStack;
	cameraStack.LoadIdentity();

	cameraStack.Translate(object->GetPosition().x, object->GetPosition().y, object->GetPosition().z);
	cameraStack.MultMatrix(object->GetRotationMatrix());

	cameraStack.PushMatrix();

		cameraStack.Translate(offset.x, offset.y, offset.z);
		position = Vector3(cameraStack.Top().a[12], cameraStack.Top().a[13], cameraStack.Top().a[14]);

		cameraStack.PushMatrix();

			cameraStack.Translate(0.0f, 0.0f, 1.0f);
			target = Vector3(cameraStack.Top().a[12], cameraStack.Top().a[13], cameraStack.Top().a[14]);
			view = (target - position).Normalized();

		cameraStack.PopMatrix();

		cameraStack.PushMatrix();

			cameraStack.Translate(-1.0f, 0.0f, 0.0f);
			right = (Vector3(cameraStack.Top().a[12], cameraStack.Top().a[13], cameraStack.Top().a[14]) - position).Normalized();

		cameraStack.PopMatrix();

		cameraStack.PushMatrix();

			cameraStack.Translate(0.0f, 1.0f, 0.0f);
			up = (Vector3(cameraStack.Top().a[12], cameraStack.Top().a[13], cameraStack.Top().a[14]) - position).Normalized();

		cameraStack.PopMatrix();

	cameraStack.PopMatrix();


}

void Camera::UpdateXRotation(double &dt) {

}

void Camera::Rotate(Vector3 rotation) {

	Mtx44 rotate;
	rotate.SetToRotation(rotation.x, 1, 0, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.y, 0, 1, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.z, 0, 0, 1);
	rotationMatrix = rotationMatrix * rotate;

}

void Camera::Rotate(float x, float y, float z) {

	Rotate(Vector3(x, y, z));

}

//Setters
void Camera::SetPosition(float x, float y, float z) {

	SetPosition(x, y, z);

}

void Camera::SetPosition(Vector3 position) {

	this->position = position;

}

void Camera::SetToRotation(Vector3 rotation) {

	rotationMatrix.SetToIdentity();
	Rotate(rotation);

}

void Camera::SetToRotation(float x, float y, float z) {

	SetToRotation(Vector3(x, y, z));

}

void Camera::SetTarget(Vector3 target) {

	this->target = target;

}

void Camera::SetTarget(float x, float y, float z) {

	SetTarget(Vector3(x, y, z));

}

//Getters
Vector3 Camera::GetPosition() {

	return this->position;

}

Vector3 Camera::GetTarget() {

	return this->target;

}

Vector3 Camera::GetUp() {

	return this->up;

}

Vector3 Camera::GetView() {

	return this->view;

}

Vector3 Camera::GetRight() {

	return this->right;

}
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

//void Camera::UpdateXRotation(double &dt) {
//}

/**********************************************************************************************************************/
/*!

\brief
Rotates the Camera.

\param rotation
The rotation to rotate the Camera by.

*/
/**********************************************************************************************************************/
void Camera::Rotate(Vector3 rotation) {

	Mtx44 rotate;
	rotate.SetToRotation(rotation.z, 0, 0, 1);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.x, 1, 0, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.y, 0, 1, 0);
	rotationMatrix = rotationMatrix * rotate;
	
}

/**********************************************************************************************************************/
/*!

\brief
Rotates the Camera.

\param x
The angle to rotate the Camera by on the x axis.

\param y
The angle to rotate the Camera by on the y axis.

\param z
The angle to rotate the Camera by on the z axis.

*/
/**********************************************************************************************************************/
void Camera::Rotate(float x, float y, float z) {

	Rotate(Vector3(x, y, z));

}

//Setters
/**********************************************************************************************************************/
/*!

\brief
Sets the position of the Camera.

\param x
The new x position of the Camera.

\param y
The new y position of the Camera.

\param z
The new z position of the Camera.

*/
/**********************************************************************************************************************/
void Camera::SetPosition(float x, float y, float z) {

	SetPosition(x, y, z);

}

/**********************************************************************************************************************/
/*!

\brief
Sets the position of the Camera.

\param position
The new position of the Camera.

*/
/**********************************************************************************************************************/
void Camera::SetPosition(Vector3 position) {

	this->position = position;

}

/**********************************************************************************************************************/
/*!

\brief
Sets the rotation of the camera.

\param rotation
The new rotation of the camera.

*/
/**********************************************************************************************************************/
void Camera::SetToRotation(Vector3 rotation) {

	rotationMatrix.SetToIdentity();
	Rotate(rotation);

}

/**********************************************************************************************************************/
/*!

\brief
Sets the rotation of the camera.

\param x
The new x rotation of the camera.

\param y
The new y rotation of the camera.

\param z
The new z rotation of the camera.

*/
/**********************************************************************************************************************/
void Camera::SetToRotation(float x, float y, float z) {

	SetToRotation(Vector3(x, y, z));

}

/**********************************************************************************************************************/
/*!

\brief
Sets the target of the Camera.

\param target
The position of the target.

*/
/**********************************************************************************************************************/
void Camera::SetTarget(Vector3 target) {

	this->target = target;

}

/**********************************************************************************************************************/
/*!

\brief
Sets the target of the Camera.

\param x
The x position of the target.

\param y
The y position of the target.

\param z
The z position of the target.

*/
/**********************************************************************************************************************/
void Camera::SetTarget(float x, float y, float z) {

	SetTarget(Vector3(x, y, z));

}

//Getters
/**********************************************************************************************************************/
/*!

\brief
Gets the position of the Camera.

\return
Returns the position of the Camera.

*/
/**********************************************************************************************************************/
Vector3 Camera::GetPosition() {

	return this->position;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the position of the Camera's target.

\return
Returns the position of the Camera's target.

*/
/**********************************************************************************************************************/
Vector3 Camera::GetTarget() {

	return this->target;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the up vector of the Camera.

\return
Returns the up vector of the Camera.

*/
/**********************************************************************************************************************/
Vector3 Camera::GetUp() {

	return this->up;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the view vector of the Camera.

\return
Returns the view vector of the Camera.

*/
/**********************************************************************************************************************/
Vector3 Camera::GetView() {

	return this->view;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the right vector of the Camera.

\return
Returns the right vector of the Camera.

*/
/**********************************************************************************************************************/
Vector3 Camera::GetRight() {

	return this->right;

}
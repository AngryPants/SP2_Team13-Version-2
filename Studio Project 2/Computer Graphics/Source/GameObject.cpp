/****************************************************************************/
/*!
\file GameObject.cpp
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for GameObject

*/
/****************************************************************************/

#include "GameObject.h"

/*************************************************************************************************************************/
/*!

\brief
A constructor of GameObject.

\param name
The name of the GameObject.

\param meshFile
The file path of the OBJ.

\param textureFile
The file path of the texture.

\param material
The material of the mesh.

*/
/*************************************************************************************************************************/
GameObject::GameObject(string name, string meshFile, const char* textureFile, Material material) {

	this->name = name;
	this->position = Vector3(0, 0, 0);
	this->mesh = MeshBuilder::GenerateOBJ(name, meshFile);	this->mesh->textureID = LoadTGA(textureFile);
	this->mesh->material = material;
	this->rotationMatrix.SetToIdentity();
	Enable();

}

/*************************************************************************************************************************/
/*!

\brief
An empty destructor.

*/
/*************************************************************************************************************************/
GameObject::~GameObject() {
}

//Functions
/*************************************************************************************************************************/
/*!

\brief
Translates the GameObject.

\param translation
How much to translate the GameObject by.

*/
/*************************************************************************************************************************/
void GameObject::Translate(Vector3 translation) {

	this->position += translation;

}

/*************************************************************************************************************************/
/*!

\brief
Translates the GameObject.

\param x
How much to translate the GameObject by on the x axis.

\param y
How much to translate the GameObject by on the y axis.

\param z
How much to translate the GameObject by on the z axis.

*/
/*************************************************************************************************************************/
void GameObject::Translate(float x, float y, float z) {

	Translate(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Rotates the GameObject.

\param translation
How much to rotate the GameObject by.

*/
/*************************************************************************************************************************/
void GameObject::Rotate(Vector3 rotation) {

	Mtx44 rotate;
	rotate.SetToRotation(rotation.z, 0, 0, 1);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.x, 1, 0, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.y, 0, 1, 0);
	rotationMatrix = rotationMatrix * rotate;
	
}

/*************************************************************************************************************************/
/*!

\brief
Rotates the GameObject.

\param x
How much to rotate the GameObject by on the x axis.

\param y
How much to rotate the GameObject by on the y axis.

\param z
How much to rotate the GameObject by on the z axis.

*/
/*************************************************************************************************************************/
void GameObject::Rotate(float x, float y, float z) {

	Rotate(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Rotates the GameObject.

\param translation
How much to rotate the GameObject by.

*/
/*************************************************************************************************************************/
void GameObject::Rotate(Mtx44 rotation) {

	rotationMatrix = rotationMatrix * rotation;

}

/*************************************************************************************************************************/
/*!

\brief
Enables the GameObject. Used to determine whether to render/interact with the object.

*/
/*************************************************************************************************************************/
void GameObject::Enable() {

	this->disabled = false;

}

/*************************************************************************************************************************/
/*!

\brief
Disables the GameObject. Used to determine whether to render/interact with the object.

*/
/*************************************************************************************************************************/
void GameObject::Disable() {

	this->disabled = true;

}

//Is-ter

/*************************************************************************************************************************/
/*!

\brief
Gets whether the GameObject is enabled or disabled.

\return
Returns a true if the GameObject is disabled or a false of the GameObject is not disabled.

*/
/*************************************************************************************************************************/
bool GameObject::IsDisabled() {

	if (disabled) {
	
		return true;

	}

	return false;

}

//Getters
/*************************************************************************************************************************/
/*!

\brief
Gets the name of the GameObject.

\return
Returns the name of the GameObject.

*/
/*************************************************************************************************************************/
string GameObject::GetName() {

	return this->name;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the position of the GameObject.

\return
Returns the position of the GameObject.

*/
/*************************************************************************************************************************/
Vector3 GameObject::GetPosition() {

	return this->position;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the forward vector of the GameObject.

\return
Returns the direction the GameObject is facing.

*/
/*************************************************************************************************************************/
Vector3 GameObject::GetForwardVector() {

	Mtx44 forward;
	forward.SetToTranslation(0, 0, 1);
	forward = rotationMatrix * forward;
	return Vector3(forward.a[12], forward.a[13], forward.a[14]).Normalized();

}

/*************************************************************************************************************************/
/*!

\brief
Gets the up vector of the GameObject.

\return
Returns the direction the top of the GameObject is facing.

*/
/*************************************************************************************************************************/
Vector3 GameObject::GetUpVector() {

	Mtx44 up;
	up.SetToTranslation(0, 1, 0);
	up = rotationMatrix * up;
	return Vector3(up.a[12], up.a[13], up.a[14]).Normalized();

}

/*************************************************************************************************************************/
/*!

\brief
Gets the right vector of the GameObject.

\return
Returns the direction the right of the GameObject is facing.

*/
/*************************************************************************************************************************/
Vector3 GameObject::GetRightVector() {

	Mtx44 right;
	right.SetToTranslation(-1, 0, 0);
	right = rotationMatrix * right;
	return Vector3(right.a[12], right.a[13], right.a[14]).Normalized();

}

/*************************************************************************************************************************/
/*!

\brief
Gets the mesh of the GameoObject.

\return
Returns a pointer to the Mesh of the GameObject.

*/
/*************************************************************************************************************************/
Mesh* GameObject::GetMesh() {

	return this->mesh;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the rotation matrix of the GameObject.

\return
Returns the Mtx44 of the rotation of the GameObject.

*/
/*************************************************************************************************************************/
Mtx44 GameObject::GetRotationMatrix() {

	return this->rotationMatrix;

}

//Setters
/*************************************************************************************************************************/
/*!

\brief
Sets the position of the GameObject.

\param position
The new position of the GameObject.

*/
/*************************************************************************************************************************/
void GameObject::SetPosition(Vector3 position) {

	this->position = position;

}

/*************************************************************************************************************************/
/*!

\brief
Sets the position of the GameObject.

\param position
The new position of the GameObject.

*/
/*************************************************************************************************************************/
void GameObject::SetPosition(float x, float y, float z) {

	SetPosition(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Sets the rotation of the GameObject.

\param position
The new rotation of the GameObject.

*/
/*************************************************************************************************************************/
void GameObject::SetRotation(Vector3 rotation) {

	rotationMatrix.SetToIdentity();
	Rotate(rotation);

}

/*************************************************************************************************************************/
/*!

\brief
Sets the rotation of the GameObject.

\param position
The new rotation of the GameObject.

*/
/*************************************************************************************************************************/
void GameObject::SetRotation(float x, float y, float z) {

	SetRotation(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Sets the rotation of the GameObject.

\param position
The new rotation of the GameObject.

*/
/*************************************************************************************************************************/
void GameObject::SetRotation(Mtx44 rotation) {

	this->rotationMatrix = rotation;

}
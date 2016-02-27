#include "GameObject.h"

GameObject::GameObject(string name, string meshFile, const char* textureFile, Material material) {

	this->name = name;
	this->position = Vector3(0, 0, 0);
	this->mesh = MeshBuilder::GenerateOBJ(name, meshFile);
	this->mesh->textureID = LoadTGA(textureFile);
	this->mesh->material = material;
	this->rotationMatrix.SetToIdentity();
	Enable();

}

GameObject::~GameObject() {
}

//Functions
void GameObject::Translate(Vector3 translation) {

	this->position += translation;

}

void GameObject::Translate(float x, float y, float z) {

	Translate(Vector3(x, y, z));

}

void GameObject::Rotate(Vector3 rotation) {

	Mtx44 rotate;
	rotate.SetToRotation(rotation.x, 1, 0, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.y, 0, 1, 0);
	rotationMatrix = rotationMatrix * rotate;
	rotate.SetToRotation(rotation.z, 0, 0, 1);
	rotationMatrix = rotationMatrix * rotate;

}

void GameObject::Rotate(float x, float y, float z) {

	Rotate(Vector3(x, y, z));

}

void GameObject::Rotate(Mtx44 rotation) {

	rotationMatrix = rotationMatrix * rotation;

}

void GameObject::Enable() {

	this->disabled = false;

}

void GameObject::Disable() {

	this->disabled = true;

}

//Is-ter
bool GameObject::IsDisabled() {

	if (disabled) {
	
		return true;

	}

	return false;

}

//Getters
string GameObject::GetName() {

	return this->name;

}

Vector3 GameObject::GetPosition() {

	return this->position;

}

Vector3 GameObject::GetForwardVector() {

	Mtx44 forward;
	forward.SetToTranslation(0, 0, 1);
	forward = rotationMatrix * forward;
	return Vector3(forward.a[12], forward.a[13], forward.a[14]).Normalized();

}

Vector3 GameObject::GetUpVector() {

	Mtx44 up;
	up.SetToTranslation(0, 1, 0);
	up = rotationMatrix * up;
	return Vector3(up.a[12], up.a[13], up.a[14]).Normalized();

}

Vector3 GameObject::GetRightVector() {

	Mtx44 right;
	right.SetToTranslation(-1, 0, 0);
	right = rotationMatrix * right;
	return Vector3(right.a[12], right.a[13], right.a[14]).Normalized();

}

Mesh* GameObject::GetMesh() {

	return this->mesh;

}

Mtx44 GameObject::GetRotationMatrix() {

	return this->rotationMatrix;

}

//Setters
void GameObject::SetPosition(Vector3 position) {

	this->position = position;

}

void GameObject::SetPosition(float x, float y, float z) {

	SetPosition(Vector3(x, y, z));

}

void GameObject::SetRotation(Vector3 rotation) {

	rotationMatrix.SetToIdentity();
	Rotate(rotation);

}

void GameObject::SetRotation(float x, float y, float z) {

	SetRotation(Vector3(x, y, z));

}

void GameObject::SetRotation(Mtx44 rotation) {

	this->rotationMatrix = rotation;

}
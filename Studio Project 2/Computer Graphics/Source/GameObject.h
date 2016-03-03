/****************************************************************************/
/*!
\file GameObject.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for GameObject

*/
/****************************************************************************/

#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTGA.h"
#include "MeshBuilder.h"
#include "MaterialList.h"
#include "Vector3.h"
#include "MatrixStack.h"

using std::string;
/****************************************************************************************/
/*!
		Class GameObject
\brief
Class to define a GameObject, the base class for all objects in the game.

*/
/****************************************************************************************/
class GameObject {

protected:
	//Variables
	bool disabled;
	string name;
	Vector3 position;
	Mtx44 rotationMatrix;
	Mesh* mesh;

	//Constructor
	GameObject(string name, string meshFile, const char* textureFile, Material material);

public:
	//Destructor
	virtual ~GameObject();

	//Functions
	void Translate(Vector3 translation);
	void Translate(float x, float y, float z);
	void Rotate(Vector3 rotation);
	void Rotate(float x, float y, float z);
	void Rotate(Mtx44 rotation);
	void Enable();
	void Disable();

	//Is-ters
	bool IsDisabled();

	//Getters
	string GetName();
	Vector3 GetPosition();
	Vector3 GetForwardVector();
	Vector3 GetUpVector();
	Vector3 GetRightVector();
	Mesh* GetMesh();
	Mtx44 GetRotationMatrix();

	//Setters
	void SetPosition(Vector3 position);
	void SetPosition(float x, float y, float z);
	void SetRotation(Vector3 rotation);
	void SetRotation(float x, float y, float z);
	void SetRotation(Mtx44 rotation);

};

#endif
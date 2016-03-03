#ifndef SCENE_H
#define SCENE_H
/****************************************************************************/
/*!
\file Scene.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "GL\glew.h"
#include "Mtx44.h"
#include "Application.h"
#include "shader.hpp"
#include "Camera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include <iostream>

using std::cout;
using std::endl;
/******************************************************************************/
/*!
		Class Scene:
\brief
*/
/******************************************************************************/
class Scene {

public:
	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

};

#endif
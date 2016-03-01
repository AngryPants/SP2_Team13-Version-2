#ifndef _GAMESCENE_H
#define _GAMESCENE_H

#include "Application.h"
#include "Scene.h"
#include "Asteroid.h"
#include "Camera.h"
#include "Light.h"
#include <list>
#include "shader.hpp"
#include "Utility.h"
#include "PlayerControl.h"
#include "Collision.h"

using std::list;

class GameScene : public Scene {

protected:
	enum GEOMETRY_TYPE {
	
		//Skybox
		SKYBOX_TOP = 0,
		SKYBOX_BOTTOM,
		SKYBOX_FRONT,
		SKYBOX_LEFT,
		SKYBOX_BACK,
		SKYBOX_RIGHT,

		//Text
		FONT_CONSOLAS,

		NUM_GEOMETRY,

	};

	//Mesh
	Mesh* mesh[NUM_GEOMETRY];

	//Camera
	Camera camera;
	
	//Matrix Stacks
	MS modelStack, viewStack, projectionStack;

	//Uniform Type
	enum UNIFORM_TYPE {
		
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,

		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_TYPE,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_TYPE,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,

		U_LIGHT3_POSITION,
		U_LIGHT3_COLOR,
		U_LIGHT3_POWER,
		U_LIGHT3_KC,
		U_LIGHT3_KL,
		U_LIGHT3_KQ,
		U_LIGHT3_SPOTDIRECTION,
		U_LIGHT3_TYPE,
		U_LIGHT3_COSCUTOFF,
		U_LIGHT3_COSINNER,
		U_LIGHT3_EXPONENT,

		U_LIGHT4_POSITION,
		U_LIGHT4_COLOR,
		U_LIGHT4_POWER,
		U_LIGHT4_KC,
		U_LIGHT4_KL,
		U_LIGHT4_KQ,
		U_LIGHT4_SPOTDIRECTION,
		U_LIGHT4_TYPE,
		U_LIGHT4_COSCUTOFF,
		U_LIGHT4_COSINNER,
		U_LIGHT4_EXPONENT,

		U_LIGHT5_POSITION,
		U_LIGHT5_COLOR,
		U_LIGHT5_POWER,
		U_LIGHT5_KC,
		U_LIGHT5_KL,
		U_LIGHT5_KQ,
		U_LIGHT5_SPOTDIRECTION,
		U_LIGHT5_TYPE,
		U_LIGHT5_COSCUTOFF,
		U_LIGHT5_COSINNER,
		U_LIGHT5_EXPONENT,

		U_LIGHTENABLED,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_TOTAL,

	};

	//Light
	Light light[6];

	//OpenGL Things
	unsigned int m_programID;
	unsigned int m_parameters[U_TOTAL];
	unsigned int m_vertexArrayID;

	//Render Functions
	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderText(Mesh* mesh, std::string text, Colour colour);
	void RenderTextWithDepth(Mesh* mesh, std::string text, Colour colour);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Colour colour, float size, float x, float y);
	void RenderObjectOnScreen(Mesh* mesh, float sizex, float sizey, float sizez, float x, float y, float z,float rotate, float rx, float ry, float rz);
	void RenderObject(GameObject* object, bool enableLight);
	void RenderSkybox();

	//Functions
	void BoundsChecking(GameObject* object, Vector3 boundarySize);
	void BoundsChecking(GameObject* object, float radius);

	//Setters
	void SetSkybox(const char* topTexture, const char* bottomTexture, const char* frontTexture, const char* leftTexture, const char* backTexture, const char* rightTexture);

	//Constructor
	GameScene();

public:
	//Destructor
	virtual ~GameScene();

	//Public Functions
	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

};

#endif
#include "Hangar.h"
#include<iostream>

Hangar::Hangar() {
}

Hangar::~Hangar() {
}

void Hangar::Init() { //Initialise Vertex Buffer Object (VBO) here.

	//Set the background colour to dark blue.
	glClearColor(0.2f, 0.0f, 0.25f, 0.0f);

	Mtx44 projection;

	projection.SetToPerspective(75.0f, (float)(glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / (glfwGetVideoMode(glfwGetPrimaryMonitor())->height), 0.1f, 5000.0f); //FOV, Aspect Ratio, Near Plane, Far Plane.
	projectionStack.LoadMatrix(projection);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	light[0].type = Light::LIGHT_DIRECTIONAL;
	light[0].position.Set(-20, 120, -15);
	light[0].colour.Set(1, 1, 1);
	light[0].power = 2.0f;
	light[0].kC = 0.1f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.0f;
	light[0].spotDirection.Set(0.0f, -1.0f, 1.0f);

	//Load vertex and fragment shaders
	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	//Use the shader
	glUseProgram(m_programID);

	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");

	//Light 0 (Directional)
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	//Make sure you pass uniform parameters after glUseProgram().
	glUniform1i(m_parameters[U_NUMLIGHTS], 1);

	//Light 0 (Directional)
	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].colour.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	//Directional Light
	Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
	Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);

	//Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	//Enable Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	SetSkybox("Image//Skybox//Top.tga", "Image//Skybox//Bottom.tga", "Image//Skybox//Front.tga", "Image//Skybox//Left.tga", "Image//Skybox//Back.tga", "Image//Skybox//Right.tga");

	meshList[HANGAR] = MeshBuilder::GenerateOBJ("Hangar", "OBJ//Space_Station//Hangar.obj");
	meshList[HANGAR]->textureID = LoadTGA("Image//Space_Station//Hangar.tga");
	meshList[HANGAR]->material = MaterialList::GetInstance()->material[MaterialList::METAL];

	player = new Player("Malcolm", "", "", "");

	player->GetShip()->SetPosition(0,2,0);

	player->SetState(MAIN_MENU);
	pause = false;
	Leave = false;
	Shop = false;
	menuOption = START;
}

void Hangar::Update(double dt) {

	CheckKeyPress();
	BoundsCheck(player->GetShip()->GetPosition());
	if (player->GetState() == MAIN_MENU)
	{
		UpdateStartMenu();
	}
	else if (player->GetState() == PLAYING)
	{
		//Player Update
		PlayerControl::RotateShip(player->GetShip(), 160.0f * dt, dt);
		if (!isPressed[S] && Application::IsKeyPressed('S'))
		{
			isPressed[S] = true;
			if (Shop)
			{
				Shop = false;
			}
			else
			{
				Shop = true;
			}
		}
		else if (!isPressed[E] && Application::IsKeyPressed('E') && !Shop)
		{
			Leave = true;
			player->SetState(ANIMATING);
		}

	}
	else if (player->GetState() == ANIMATING)
	{
		PlayerControl::RotateShip(player->GetShip(), 160.0f * dt, dt);
		LeavingAnimation(dt);
	}
	RigidBody* rigidBodyPointer = player->GetShip();
	RigidBody::UpdateRigidBody(rigidBodyPointer, dt);
	camera.FollowObject(player->GetShip(), Vector3(0.0f, 1.0f, 0.0f));

}

void Hangar::LeavingAnimation(double &dt)
{
	if (Leave == true)
	{
		if (player->GetShip()->GetPosition().y<5.0f)
		{
			player->GetShip()->AddForce(0,1000,0,dt);
		}
		else if (player->GetShip()->GetPosition().z < 20.0f)
		{
			player->GetShip()->AddForce(0,0,10000,dt);
			if(player->GetShip()->GetPosition().y>5.0f)
			{
				player->GetShip()->AddForce(0, -1000, 0, dt);
			}
		}
		else
		{
			SharedData::GetInstance()->sceneNumber = 2;
		}
	}
	
}

void Hangar::BoundsCheck(Vector3 position)
{

	int xLimit = 39;
	int zLimit = 19;

	if (position.x > xLimit) {

		position.x = xLimit;

	}
	else if (position.x < -xLimit) {

		position.x = -xLimit;

	}

	if (position.z > zLimit) {

		position.z = zLimit;

	}
	else if (position.z < -zLimit) {

		position.z = -zLimit;

	}

}

void Hangar::UpdateStartMenu()
{
	if (!isPressed[UP] && Application::IsKeyPressed(VK_UP)) {

		isPressed[UP] = true;

		if (menuOption != START) {

			menuOption = static_cast<MENU>(menuOption - 1);

		}

	}

	if (!isPressed[DOWN] && Application::IsKeyPressed(VK_DOWN)) {

		isPressed[DOWN] = true;

		if (menuOption != QUIT) {

			menuOption = static_cast<MENU>(menuOption + 1);

		}

	}

	if (Application::IsKeyPressed(VK_RETURN) && !isPressed[RETURN]) {

		isPressed[RETURN] = true;

		if (menuOption == START) {

			player->SetState(PLAYING);

		}
		else if (menuOption == SOUND) {

			if (SharedData::GetInstance()->soundOn == true) {

				SharedData::GetInstance()->soundOn = false;

			}
			else if (SharedData::GetInstance()->soundOn == false) {

				SharedData::GetInstance()->soundOn = true;

			}

		}
		else if (menuOption == QUIT) {

			SharedData::GetInstance()->quitGame = true;

		}

	}
}

void Hangar::CheckKeyPress() {

	if (!Application::IsKeyPressed('S')) {

		isPressed[S] = false;

	}

	if (!Application::IsKeyPressed(VK_UP)) {

		isPressed[UP] = false;

	}

	if (!Application::IsKeyPressed(VK_DOWN)) {

		isPressed[DOWN] = false;

	}

	if (!Application::IsKeyPressed(VK_RETURN)) {

		isPressed[RETURN] = false;

	}

	if (!Application::IsKeyPressed(VK_BACK)) {

		isPressed[BACK] = false;

	}

	if (!Application::IsKeyPressed('E')) {

		isPressed[E] = false;

	}

}

void Hangar::Render() { //Render VBO here.

	//Clear colour & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z, camera.GetTarget().x, camera.GetTarget().y, camera.GetTarget().z, camera.GetUp().x, camera.GetUp().y, camera.GetUp().z);

	//Directional Light
	Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
	Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);


	modelStack.LoadIdentity();
	RenderSkybox();
	if (player->GetState() == MAIN_MENU)
	{
		RenderStartMenu();
	}
	else if (player->GetState() == PLAYING || player->GetState() == ANIMATING)
	{
		RenderObjects();	
		RenderObject(player->GetShip(), true);
		RenderUI();
	}
}

void Hangar::RenderStartMenu()
{
	Colour textColour = Colour(1.0f, 0.0f, 0.0f);
	float textSize = 100.0f;
	float posX = 8.7f;
	float posY = 6.0f;

	if (menuOption == START)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], ">", textColour, textSize, posX - 1.0f, posY);
	}
	else if (menuOption == SOUND)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], ">", textColour, textSize, posX - 1.0f, posY - 1.0f);
	}
	else if (menuOption == QUIT)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], ">", textColour, textSize, posX - 1.0f, posY - 2.0f);
	}

	if (player->GetState() == MAIN_MENU)
	{
		if (pause)
		{
			RenderTextOnScreen(mesh[FONT_CONSOLAS], "CONTINUE", textColour, textSize, posX, posY);
		}
		else
		{
			RenderTextOnScreen(mesh[FONT_CONSOLAS], "START", textColour, textSize, posX, posY);
		}
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "SOUND", textColour, textSize, posX, posY - 1.0f);

		RenderTextOnScreen(mesh[FONT_CONSOLAS], "QUIT", textColour, textSize, posX, posY - 2.0f);

		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Press Enter to select.", textColour, textSize, 6.5f, posY - 4.0f);

	}
}

void Hangar::RenderUI()
{
	if (Shop)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Ship Health : "+ std::to_string(((int)player->GetShip()->GetMaxHealth())), Colour(1, 0, 0), 100, 1, 8);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Gold : " + std::to_string(((int)player->GetInventory()->GetGold())), Colour(1, 1, 0.1), 100, 1, 7);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "veldspar : " + std::to_string(((int)player)), Colour(0.5, 0.5, 0.5), 100, 1, 6);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "omber : " + std::to_string(((int)player->GetShip()->GetHealth())), Colour(0.5, 0.35, 0.05), 100, 1, 5);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "kernite : " + std::to_string(((int)player->GetInventory()->GetGold())), Colour(0, 1, 1), 100, 1, 4);
		
	}
	else
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "PRESS E TO TAKE OFF", Colour(0, 1, 0), 70, 11, 14.8);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "PRESS S TO VIEW SHOP", Colour(1, 0, 0), 70, 11, 1);
	}
}

void Hangar::RenderObjects()
{
	modelStack.PushMatrix();
	modelStack.Scale(4,4,4);
	RenderMesh(meshList[HANGAR],true);
	modelStack.PopMatrix();
}

void Hangar::Exit() {

	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);

}
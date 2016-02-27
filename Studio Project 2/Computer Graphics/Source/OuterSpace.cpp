#include "OuterSpace.h"

#include<iostream>
OuterSpace::OuterSpace() {
}

OuterSpace::~OuterSpace() {
}

void OuterSpace::Init() { //Initialise Vertex Buffer Object (VBO) here.

	//Set the background colour to dark blue.
	glClearColor(0.2f, 0.0f, 0.25f, 0.0f);

	Mtx44 projection;
	
	projection.SetToPerspective(75.0f, (float)(glfwGetVideoMode(glfwGetPrimaryMonitor())->width)/(glfwGetVideoMode(glfwGetPrimaryMonitor())->height), 0.1f, 5000.0f); //FOV, Aspect Ratio, Near Plane, Far Plane.
	projectionStack.LoadMatrix(projection);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	
	light[0].type = Light::LIGHT_DIRECTIONAL;
	light[0].position.Set(-20, 100, -15);
	light[0].colour.Set(1, 1, 1);
	light[0].power = 1.0f;
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
	Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
	Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
	glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
	
	//Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	//Enable Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	SetSkybox("Image//Skybox//Top.tga", "Image//Skybox//Bottom.tga", "Image//Skybox//Front.tga", "Image//Skybox//Left.tga", "Image//Skybox//Back.tga", "Image//Skybox//Right.tga");

	//enemies.push_back(new Drone());
	//enemies.push_back(new Drone());
	//enemies.push_back(new Drone());
	//enemies.push_back(new Drone());
	//enemies.push_back(new Drone());

	for (int i = 0; i < 5; ++i)
	{
		Spawn::SpawnObjects(new Drone(), i, Vector3(-1025, -1025, 1025), 3300.0f, enemies);
		Spawn::SpawnObjects(new Pirate(), i, Vector3(1025, -1025, -1025), 3300.0f, enemies);
		Spawn::SpawnObjects(new Alien(), i, Vector3(-1025, -1025, -1025), 3300.0f, enemies);

		Spawn::SpawnObjects(new Veldspar(), i, Vector3(-1025, 1025, 1025), 3300.0f, asteroids);
		Spawn::SpawnObjects(new Omber(), i, Vector3(1025, 1025, -1025), 3300.0f, asteroids);
		Spawn::SpawnObjects(new Kernite(), i, Vector3(-1025, 1025, -1025), 3300.0f, asteroids);
	}

	player = new Player("Malcolm", "", "", "");

	player->GetShip()->SetPosition(80,80,80);
	iSpaceObjects.push_back(new CarrickStation());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	iSpaceObjects.push_back(new Portal());
	warning = false;
	player->GetShip()->SetPosition(50, 10, 5);

}

void OuterSpace::Update(double dt) {

	BoundCheck();
	PlayerControl::RotateShip(player->GetShip(), 160.0f * dt, dt);
	PlayerControl::MoveShip(player->GetShip(), 50000.0f, dt);
	PlayerControl::Shoot(player->GetShip(), camera.GetPosition() + player->GetShip()->GetForwardVector());
	player->GetShip()->Update(dt);

	for (list<Ship*>::iterator iter = enemies.begin(); iter != enemies.end(); ++iter) {
	
		AI::FaceTarget(*iter, player->GetShip(), 240 * dt, dt);
		AI::MoveToTarget(*iter, player->GetShip(), 9000.0f, dt);
		AI::ShootAtTarget(*iter, player->GetShip());
		(*iter)->Update(dt);
		
		SpaceObject* spaceObjectPointer1 = *iter;
		SpaceObject* spaceObjectPointer2 = player->GetShip();
		Collision::SpaceObjectToSpaceObject(spaceObjectPointer1, spaceObjectPointer2, dt);
		
		RigidBody* rigidBodyPointer = *iter;
		RigidBody::UpdateRigidBody(rigidBodyPointer, dt);
		
	}

	RigidBody* rigidBodyPointer = player->GetShip();
	RigidBody::UpdateRigidBody(rigidBodyPointer, dt);

	camera.FollowObject(player->GetShip(), Vector3(0.0f, 3.0f, - 15.0f));

}

void OuterSpace::BoundCheck()
{
	if (player->GetShip()->GetPosition().x>2000 || player->GetShip()->GetPosition().x<-2000 || player->GetShip()->GetPosition().y>2000 || player->GetShip()->GetPosition().y<-2000 || player->GetShip()->GetPosition().z>2000 || player->GetShip()->GetPosition().z<-2000)
	{
		warning = true;
	}
	else
	{
		warning = false;
	}

	if (player->GetShip()->GetPosition().x>2400 || player->GetShip()->GetPosition().x<-2400 || player->GetShip()->GetPosition().y>2400 || player->GetShip()->GetPosition().y<-2400 || player->GetShip()->GetPosition().z>2400 || player->GetShip()->GetPosition().z<-2400)
	{
		int shortestDist = 10000;
		Vector3 location;
		for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it)
		{
			if ((*it)->GetName() == "Portal")
			{
				int temp = Physics::getDistance(player->GetShip()->GetPosition(), (*it)->GetPosition());
				if (shortestDist > temp)
				{
					shortestDist = temp;
					location.Set((*it)->GetPosition().x, (*it)->GetPosition().y, (*it)->GetPosition().z);
				}
			}
			if (iSpaceObjects.back() != 0)
			{
				player->GetShip()->SetPosition(location.x, location.y, location.z);
			}
		}
	}

	Spawn::UpdateObjects(player->GetShip()->GetPosition(), zoneCenter);

}

void OuterSpace::Render() { //Render VBO here.

	//Clear colour & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z, camera.GetTarget().x, camera.GetTarget().y, camera.GetTarget().z, camera.GetUp().x, camera.GetUp().y, camera.GetUp().z);

	modelStack.LoadIdentity();

	RenderSkybox();
	RenderObjects();
	RenderObject(player->GetShip(), true);

	for (list<Bullet>::iterator bullet_iter = (*player->GetShip()->GetBullets()).begin(); bullet_iter != (*player->GetShip()->GetBullets()).end(); ++bullet_iter) {
		
		RenderObject(&(*bullet_iter), false);

	}

	for (list<Ship*>::iterator ship_iter = enemies.begin(); ship_iter != enemies.end(); ++ship_iter) {
		
		if ((Physics::getDistance(player->GetShip()->GetPosition(), zoneCenter) <= 3400.0f) && 
			(Physics::getDistance((*ship_iter)->GetPosition(), zoneCenter) <= 3300.0f)) {

			RenderObject(*ship_iter, true);
		}

		for (list<Bullet>::iterator bullet_iter = (*(*ship_iter)->GetBullets()).begin(); bullet_iter != (*(*ship_iter)->GetBullets()).end(); ++bullet_iter) {
		
			RenderObject(&(*bullet_iter), false);

		}

	}

	for (list<Asteroid*>::iterator asteroid_iter = asteroids.begin(); asteroid_iter != asteroids.end(); ++asteroid_iter){

		if ((Physics::getDistance(player->GetShip()->GetPosition(), zoneCenter) <= 3400.0f) && 
			(Physics::getDistance((*asteroid_iter)->GetPosition(), zoneCenter) <= 3300.0f))	{

			RenderObject(*asteroid_iter, true);
		}
	}

	if (warning)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Going out of Bounds,please Turn back", Colour(1, 0, 0), 100, 4.0f, 7.0f);
	}
	for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it)
	{
		RenderTextOnScreen(mesh[FONT_CONSOLAS], (*it)->GetRenderMessage(), Colour(1, 0, 0), 100, 4.0f, 1.0f);
	}

	RenderTextOnScreen(mesh[FONT_CONSOLAS], "X: " + std::to_string(player->GetShip()->GetPosition().x) + "Y: " + std::to_string(player->GetShip()->GetPosition().y) + "Z: " + std::to_string(player->GetShip()->GetPosition().z), Colour(0, 1, 0), 100, 6, 6);
	RenderTextOnScreen(mesh[FONT_CONSOLAS], std::to_string((int)player->GetShip()->GetHealth()), Colour(1, 0, 0), 100, 3, 3);

}

void OuterSpace::RenderObjects()
{
	int x, y, z;
	int no = 1;
	for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it)
	{
		modelStack.PushMatrix();
		if ((*it)->GetName() == "OuterSpaceStation")
		{
			modelStack.Translate((*it)->GetPosition().x, (*it)->GetPosition().y, (*it)->GetPosition().z);
			RenderMesh((*it)->GetMesh(), true);

		}
		else if ((*it)->GetName() == "Portal")
		{
			switch (no)
			{
			case 1:x = 1, y = 1, z = 1; break;
			case 2:x = -1, y = 1, z = 1; break;
			case 3:x = -1, y = -1, z = 1; break;
			case 4:x = -1, y = 1, z = -1; break;
			case 5:x = -1, y = -1, z = -1; break;
			case 6:x = 1, y = -1, z = -1; break;
			case 7:x = 1, y = 1, z = -1; break;
			case 8:x = 1, y = -1, z = 1; break;
			}

			modelStack.Translate(1750 * x, 1750 * y, 1750 * z);
			(*it)->SetPosition(1750 * x, 1750 * y, 1750 * z);
			no++;
			RenderMesh((*it)->GetMesh(), true);
		}
		modelStack.PopMatrix();
	}
}

void OuterSpace::Exit() {

	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);

}
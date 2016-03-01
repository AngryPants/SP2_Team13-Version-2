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
	
	projection.SetToPerspective(75.0f, (float)(glfwGetVideoMode(glfwGetPrimaryMonitor())->width)/(glfwGetVideoMode(glfwGetPrimaryMonitor())->height), 0.1f, 6000.0f); //FOV, Aspect Ratio, Near Plane, Far Plane.
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

	meshList[CROSSHAIR] = MeshBuilder::GenerateQuad("Crosshair", Colour(1, 0, 0), 1,1);
	meshList[CROSSHAIR]->textureID = LoadTGA("Image//UI//Crosshair.tga");

	meshList[MAXHEALTH] = MeshBuilder::GenerateQuad("MAX HP", Colour(1, 0, 0), 1, 1);
	meshList[MAXHEALTH]->textureID = LoadTGA("Image//UI//Life//MaxLife.tga");

	meshList[CURRHEALTH] = MeshBuilder::GenerateQuad("Current HP", Colour(0, 1, 0), 1,1);
	meshList[CURRHEALTH]->textureID = LoadTGA("Image//UI//Life//CurrentLife.tga");

	meshList[DISPLAY] = MeshBuilder::GenerateQuad("Display",Colour(0,1,0),1,1);
	meshList[DISPLAY]->textureID = LoadTGA("Image//UI//Overlay//TextDisplay.tga");

	meshList[TAB] = MeshBuilder::GenerateQuad("Tab", Colour(0, 1, 0), 1, 1);
	meshList[TAB]->textureID = LoadTGA("Image//UI//Overlay//QuestScreen.tga");

	player = new Player("Malcolm", "", "", "");

	iSpaceObjects.push_back(new CarrickStation());

	iSpaceObjects.push_back(new WarpGate("Warp Gate Anna 1", Vector3(1750, 1750, 1750), Vector3(190, 190, 190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Boris 1", Vector3(-1750, 1750, 1750), Vector3(-190, 190, 190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Chariton 1", Vector3(1750, -1750, 1750), Vector3(190, -190, 190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Dmitri 1", Vector3(1750, 1750, -1750), Vector3(190, 190, -190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Elena 1", Vector3(-1750, -1750, 1750), Vector3(-190, -190, 190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Fedor 1", Vector3(-1750, 1750, -1750), Vector3(-190, 190, -190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Gregory 1", Vector3(1750, -1750, -1750), Vector3(190, -190, -190)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Hariton 1", Vector3(-1750, -1750, -1750), Vector3(-190, -190, -190)));

	iSpaceObjects.push_back(new WarpGate("Warp Gate Anna 2", Vector3(150,150,150), Vector3(1710, 1710, 1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Boris 2", Vector3(-150,150,150), Vector3(-1710, 1710, 1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Chariton 2", Vector3(150,-150,150), Vector3(1710, -1710, 1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Dmitri 2", Vector3(150,150,-150), Vector3(1710, 1710, -1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Elena 2", Vector3(-150,-150,150), Vector3(-1710, -1710, 1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Fedor 2", Vector3(-150,150,-150), Vector3(-1710, 1710, -1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Gregory 2", Vector3(150,-150,-150), Vector3(1710, -1710, -1710)));
	iSpaceObjects.push_back(new WarpGate("Warp Gate Hariton 2", Vector3(-150,-150,-150), Vector3(-1710, -1710, -1710)));

	spawnZones.push_back(SpawnZone("Veldspar Zone", Vector3(-1250, 1250, -1250), 600.0f, 900.0f, 1200.0f));
	Spawn::SpawnObjects(new Veldspar(), Veldspar().GetRadius(), 25, spawnZones[0], (*spawnZones[0].GetAsteroidList()), 7990);
	spawnZones.push_back(SpawnZone("Omber Zone", Vector3(1250, 1250, 1250), 600.0f, 900.0f, 1200.0f));
	Spawn::SpawnObjects(new Omber(), Omber().GetRadius(), 25, spawnZones[1], (*spawnZones[1].GetAsteroidList()), 12);
	spawnZones.push_back(SpawnZone("Kernite Zone", Vector3(-1250, 1250, 1250), 600.0f, 900.0f, 1200.0f));
	Spawn::SpawnObjects(new Kernite(), Kernite().GetRadius(), 25, spawnZones[2], (*spawnZones[2].GetAsteroidList()), 489);
	spawnZones.push_back(SpawnZone("Drone Zone", Vector3(1250, -1250, 1250), 150.0f, 500.0f, 800.0f));
	Spawn::SpawnObjects(new Drone(), Drone().GetRadius(), 8, spawnZones[3], (*spawnZones[3].GetEnemyList()), 42);
	spawnZones.push_back(SpawnZone("Pirate Zone", Vector3(-1250, -1250, -1250), 150.0f, 500.0f, 800.0f));
	Spawn::SpawnObjects(new Pirate(), Pirate().GetRadius(), 6, spawnZones[4], (*spawnZones[4].GetEnemyList()), 234);
	spawnZones.push_back(SpawnZone("Alien Zone", Vector3(1250, -1250, -1250), 150.0f, 500.0f, 800.0f));
	Spawn::SpawnObjects(new Alien(), Alien().GetRadius(), 4, spawnZones[5], (*spawnZones[5].GetEnemyList()), 153);

	player = new Player("Malcolm", "", "", "");

	warning = false;
	player->GetShip()->SetPosition(1250, -1250, -1250);

}

void OuterSpace::Update(double dt) {

	if (Application::IsKeyPressed('1')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (Application::IsKeyPressed('2')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	//BoundsCheck();
	//Player Update
	PlayerControl::RotateShip(player->GetShip(), 160.0f * dt, dt);
	PlayerControl::MoveShip(player->GetShip(), 400000.0f, dt);
	PlayerControl::Shoot(player->GetShip(), camera.GetPosition() + player->GetShip()->GetForwardVector());
	player->GetShip()->Update(dt);

	//Update Zones
	for (vector<SpawnZone>::iterator zone_iter = spawnZones.begin(); zone_iter != spawnZones.end(); ++zone_iter) {

		Spawn::CheckZone((*zone_iter), player->GetShip()->GetPosition());

		if (zone_iter->GetZoneState() != INACTIVE) {

			//Update Enemies
			for (list<Ship>::iterator ship_iter = zone_iter->GetEnemyList()->begin(); ship_iter != zone_iter->GetEnemyList()->end(); ++ship_iter) {
			
				AI::FaceTarget(&(*ship_iter), player->GetShip(), 240 * dt, dt);
				AI::MoveToTarget(&(*ship_iter), player->GetShip(), 9000.0f, dt);
				AI::ShootAtTarget(&(*ship_iter), player->GetShip());
				ship_iter->Update(dt);
				
				SpaceObject* spaceObjectPointer1 = &(*ship_iter);
				SpaceObject* spaceObjectPointer2 = player->GetShip();
				Collision::SpaceObjectToSpaceObject(spaceObjectPointer1, spaceObjectPointer2, dt);
				
				RigidBody* rigidBodyPointer = &(*ship_iter);
				RigidBody::UpdateRigidBody(rigidBodyPointer, dt);
				
				for (list<Bullet>::iterator bullet_iter = player->GetShip()->GetBullets()->begin(); bullet_iter != player->GetShip()->GetBullets()->end(); ++bullet_iter) {
				
					Collision::BulletToSpaceObject(&(*bullet_iter), spaceObjectPointer1);
				
				}
				
				Spawn::CheckKill(spaceObjectPointer1, *player);
				
				for (list<Bullet>::iterator bullet_iter = ship_iter->GetBullets()->begin(); bullet_iter != ship_iter->GetBullets()->end(); ++bullet_iter) {
				
					Collision::BulletToSpaceObject(&(*bullet_iter), spaceObjectPointer2);
				
				}

			}

			//Update Asteroids
			for (list<Asteroid>::iterator asteroid_iter = zone_iter->GetAsteroidList()->begin(); asteroid_iter != zone_iter->GetAsteroidList()->end(); ++asteroid_iter) {
			
				SpaceObject* spaceObjectPointer1 = &(*asteroid_iter);
				SpaceObject* spaceObjectPointer2 = player->GetShip();
				Collision::SpaceObjectToSpaceObject(spaceObjectPointer1, spaceObjectPointer2, dt);

				Spawn::CheckKill(spaceObjectPointer1, *player);

				RigidBody* rigidBodyPointer = &(*asteroid_iter);
				RigidBody::UpdateRigidBody(rigidBodyPointer, dt);

			}

		}

	}

	//Interactables Update
	UpdateSpaceInteractable(dt);
		
	//}
	RigidBody* rigidBodyPointer = player->GetShip();
	RigidBody::UpdateRigidBody(rigidBodyPointer, dt);
	camera.FollowObject(player->GetShip(), Vector3(0.0f, 3.0f, - 15.0f));

}

void OuterSpace::UpdateSpaceInteractable(double &dt)
{
	bool stopLoop = false;
	for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); !stopLoop && it != iSpaceObjects.end(); it++)
	{
		stopLoop = Interaction::ShipToObject((*player), (*it), dt);
	}

}

void OuterSpace::BoundsCheck()
{
	if (player->GetShip()->GetPosition().x>2000 || player->GetShip()->GetPosition().x<-2000 || player->GetShip()->GetPosition().y>2000 || player->GetShip()->GetPosition().y<-2000 || player->GetShip()->GetPosition().z>2000 || player->GetShip()->GetPosition().z<-2000)
	{
		warning = true;
	}
	else
	{
		warning = false;
	}

	if (player->GetShip()->GetPosition().x>2200 || player->GetShip()->GetPosition().x<-2200 || player->GetShip()->GetPosition().y>2200 || player->GetShip()->GetPosition().y<-2200 || player->GetShip()->GetPosition().z>2200 || player->GetShip()->GetPosition().z<-2200)
	{
		int shortestDist = 10000;
		Vector3 location;
		for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it)
		{
			if ((*it)->GetName() != "Carrick Station")
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

}

void OuterSpace::Render() { //Render VBO here.

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

	RenderObjects();
	RenderObject(player->GetShip(), true);

	for (list<Bullet>::iterator bullet_iter = (*player->GetShip()->GetBullets()).begin(); bullet_iter != (*player->GetShip()->GetBullets()).end(); ++bullet_iter) {
		
		RenderObject(&(*bullet_iter), false);

	}

	for (vector<SpawnZone>::iterator zone_iter = spawnZones.begin(); zone_iter != spawnZones.end(); ++zone_iter) {

		if (zone_iter->GetZoneState() != INACTIVE) {
		
			//Render Enemies
			for (list<Ship>::iterator ship_iter = zone_iter->GetEnemyList()->begin(); ship_iter != zone_iter->GetEnemyList()->end(); ++ship_iter) {

				RenderObject(&(*ship_iter), true);

				for (list<Bullet>::iterator bullet_iter = ship_iter->GetBullets()->begin(); bullet_iter != ship_iter->GetBullets()->end(); ++bullet_iter) {
				
					RenderObject(&(*bullet_iter), false);

				}

			}

			//Render Asteroids
			for (list<Asteroid>::iterator asteroid_iter = zone_iter->GetAsteroidList()->begin(); asteroid_iter != zone_iter->GetAsteroidList()->end(); ++asteroid_iter) {
				
				RenderObject(&(*asteroid_iter), true);

			}

		}

	}

	UserInterFace();

}

void OuterSpace::UserInterFace()
{
	//Debug Info
	RenderTextOnScreen(mesh[FONT_CONSOLAS], "X: " + std::to_string((int)(player->GetShip()->GetPosition().x)) + " Y: " + std::to_string((int)(player->GetShip()->GetPosition().y)) + " Z: " + std::to_string((int)(player->GetShip()->GetPosition().z)), Colour(0, 1, 0), 70, 11, 14.8);

	if (Interaction::GetRenderMessage() != "")
	{
		RenderObjectOnScreen(meshList[DISPLAY], 1200 , 100, 100, 1000, 825, 180, 1, 0, 0);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], Interaction::GetRenderMessage(), Colour(0, 1, 0), 100, 5, 8);
	}
	if (warning)
	{
		RenderObjectOnScreen(meshList[DISPLAY], 1200, 100, 100, 1070, 825, 180, 1, 0, 0);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "You Are leaving Area, please turn back", Colour(0, 1, 0), 100, 5, 8);
	}

	RenderObjectOnScreen(meshList[CROSSHAIR], 50, 50, 50, 957.5, 542, 180, 1, 0, 0);
	RenderObjectOnScreen(meshList[MAXHEALTH], 600.0f, 30, 40, 955, 1000, 180, 1, 0, 0);
	RenderObjectOnScreen(meshList[CURRHEALTH], player->GetShip()->GetHealth() / player->GetShip()->GetMaxHealth() * 600.0f, 30, 40, 955, 1000, 180, 1, 0, 0);
	
	if (Application::IsKeyPressed(VK_TAB)) // UI 2
	{
		RenderObjectOnScreen(meshList[TAB], 1000, 1100, 100, 500, 550, 180, 0, 1, 0);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "STATUS", Colour(1, 0, 0), 300, 0.8, 3);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Current Health : " + std::to_string(((int)player->GetShip()->GetHealth())) + "/" + std::to_string(((int)player->GetShip()->GetMaxHealth())), Colour(1, 0, 0), 100, 1, 8);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "Gold : " + std::to_string(((int)player->GetInventory()->GetGold())), Colour(1, 1, 0.1), 100, 1, 7);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "veldspar : " /*+ std::to_string(((int)player))*/, Colour(0.5,0.5,0.5), 100, 1, 6);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "omber : "/* + std::to_string(((int)player->GetShip()->GetHealth()))*/, Colour(0.5, 0.35, 0.05), 100, 1, 5);
		RenderTextOnScreen(mesh[FONT_CONSOLAS], "kernite : " /*+ std::to_string(((int)player->GetInventory()->GetGold()))*/, Colour(0, 1, 1), 100, 1, 4);
	
	}

}

void OuterSpace::RenderObjects()
{
	for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it)
	{
		modelStack.PushMatrix();
		modelStack.Translate((*it)->GetPosition().x, (*it)->GetPosition().y, (*it)->GetPosition().z);
		RenderMesh((*it)->GetMesh(), true);
		modelStack.PopMatrix();
	}

}

void OuterSpace::Exit() {

	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);

}
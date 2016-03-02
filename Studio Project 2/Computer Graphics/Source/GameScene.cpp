#include "GameScene.h"

//Constructor
GameScene::GameScene() {

	mesh[FONT_CONSOLAS] = MeshBuilder::GenerateText("Text", 16, 16);
	mesh[FONT_CONSOLAS]->textureID = LoadTGA("Image//Fonts//Consolas.tga");

	mesh[HANGAR] = MeshBuilder::GenerateOBJ("Hangar", "OBJ//Space_Station//Hangar.obj");
	mesh[HANGAR]->textureID = LoadTGA("Image//Space_Station//Hangar.tga");
	mesh[HANGAR]->material = MaterialList::GetInstance()->material[MaterialList::METAL];

	mesh[DECO_SHIP_RED] = MeshBuilder::GenerateOBJ("Freighter", "OBJ//Freighter//Freighter.obj");
	mesh[DECO_SHIP_RED]->textureID = LoadTGA("Image//Freighter//Freighter_Red.tga");
	mesh[DECO_SHIP_RED]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[DECO_SHIP_BLUE] = MeshBuilder::GenerateOBJ("Freighter", "OBJ//Freighter//Freighter.obj");
	mesh[DECO_SHIP_BLUE]->textureID = LoadTGA("Image//Freighter//Freighter_Blue.tga");
	mesh[DECO_SHIP_BLUE]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[DECO_TRUCK] = MeshBuilder::GenerateOBJ("Avalanche", "OBJ//Avalanche//Avalanche.obj");
	mesh[DECO_TRUCK]->textureID = LoadTGA("Image//Avalanche//Avalanche.tga");
	mesh[DECO_TRUCK]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[VELDSPAR] = MeshBuilder::GenerateOBJ("VELDSPAR", "OBJ//Asteroid//Asteroid.obj");
	mesh[VELDSPAR]->textureID = LoadTGA("Image//Asteroid//Veldspar.tga");
	mesh[VELDSPAR]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->CEMENT];

	mesh[OMBER] = MeshBuilder::GenerateOBJ("OMBER", "OBJ//Asteroid//Asteroid.obj");
	mesh[OMBER]->textureID = LoadTGA("Image//Asteroid//Omber.tga");
	mesh[OMBER]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->CEMENT];

	mesh[KERNITE] = MeshBuilder::GenerateOBJ("KERNITE", "OBJ//Asteroid//Asteroid.obj");
	mesh[KERNITE]->textureID = LoadTGA("Image//Asteroid//Kernite.tga");
	mesh[KERNITE]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->CEMENT];

	mesh[PLAYER_SHIP] = MeshBuilder::GenerateOBJ("PlayerShip", "OBJ//Condor//Condor.obj");
	mesh[PLAYER_SHIP]->textureID = LoadTGA("Image//Condor//Condor.tga");
	mesh[PLAYER_SHIP]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[DRONE] = MeshBuilder::GenerateOBJ("Drone", "OBJ//Enemies//Drone.obj");
	mesh[DRONE]->textureID = LoadTGA("Image//Enemies//Drone.tga");
	mesh[DRONE]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[PIRATE] = MeshBuilder::GenerateOBJ("pirate", "OBJ//Enemies//Pirate.obj");
	mesh[PIRATE]->textureID = LoadTGA("Image//Enemies//Pirate.tga");
	mesh[PIRATE]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[ALIEN] = MeshBuilder::GenerateOBJ("Alien", "OBJ//Enemies//Alien.obj");
	mesh[ALIEN]->textureID = LoadTGA("Image//Enemies//Alien.tga");
	mesh[ALIEN]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];

	mesh[SCREEN] = MeshBuilder::GenerateQuad("Screen", Colour(1, 0, 0), 1, 1);
	mesh[SCREEN]->textureID = LoadTGA("Image//UI//BackgroundScreen.tga");
	mesh[SCREEN]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->METAL];


	//NPC
	mesh[NPC_HEAD] = MeshBuilder::GenerateOBJ("NPC_HEAD", "OBJ//NPC//Head.obj");
	mesh[NPC_HEAD]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_HEAD]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[NPC_LEFT_HAND] = MeshBuilder::GenerateOBJ("NPC_LEFT_HAND", "OBJ//NPC//Left_Arm.obj");
	mesh[NPC_LEFT_HAND]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_LEFT_HAND]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[NPC_RIGHT_HAND] = MeshBuilder::GenerateOBJ("NPC_RIGHT_HAND", "OBJ//NPC//Right_Arm.obj");
	mesh[NPC_RIGHT_HAND]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_RIGHT_HAND]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[NPC_BODY] = MeshBuilder::GenerateOBJ("NPC_BODY", "OBJ//NPC//Body.obj");
	mesh[NPC_BODY]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_BODY]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[NPC_LEFT_LEG] = MeshBuilder::GenerateOBJ("NPC_LEFT_LEG", "OBJ//NPC//Left_Leg.obj");
	mesh[NPC_LEFT_LEG]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_LEFT_LEG]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[NPC_RIGHT_LEG] = MeshBuilder::GenerateOBJ("NPC_RIGHT_LEG", "OBJ//NPC//Right_Leg.obj");
	mesh[NPC_RIGHT_LEG]->textureID = LoadTGA("Image//NPC//Benny.tga");
	mesh[NPC_RIGHT_LEG]->material = MaterialList::GetInstance()->material[MaterialList::GetInstance()->PLASTIC];

	mesh[CROSSHAIR] = MeshBuilder::GenerateQuad("Crosshair", Colour(1, 0, 0), 1, 1);
	mesh[CROSSHAIR]->textureID = LoadTGA("Image//UI//Crosshair.tga");

	mesh[MAXHEALTH] = MeshBuilder::GenerateQuad("MAX HP", Colour(1, 0, 0), 1, 1);
	mesh[MAXHEALTH]->textureID = LoadTGA("Image//UI//Life//MaxLife.tga");

	mesh[CURRHEALTH] = MeshBuilder::GenerateQuad("Current HP", Colour(0, 1, 0), 1, 1);
	mesh[CURRHEALTH]->textureID = LoadTGA("Image//UI//Life//CurrentLife.tga");

	mesh[DISPLAY] = MeshBuilder::GenerateQuad("Display", Colour(0, 1, 0), 1, 1);
	mesh[DISPLAY]->textureID = LoadTGA("Image//UI//Overlay//TextDisplay.tga");

	mesh[TAB] = MeshBuilder::GenerateQuad("Tab", Colour(0, 1, 0), 1, 1);
	mesh[TAB]->textureID = LoadTGA("Image//UI//Overlay//QuestScreen.tga");

	for (GEOMETRY_TYPE i = SKYBOX_TOP; i <= SKYBOX_RIGHT; i = static_cast<GEOMETRY_TYPE>(i + 1)) {
	
		mesh[i] = MeshBuilder::GenerateQuad("Skybox", Colour(1, 1, 1), 1.0f);
		mesh[i]->textureID = LoadTGA("Image//PlaceHolder//PlaceHolder.tga");

	}

}

//Destructor
GameScene::~GameScene() {
}

void GameScene::CheckKeyPress() {

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

void GameScene::RenderMesh(Mesh *mesh, bool enableLight) {

	Mtx44 MVP, modelView, modelView_inverse_transpose;
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);

	if(enableLight) {
		
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//Load Material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	
	} else {
	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);

	}

	if (mesh->textureID > 0) {
	
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	} else {
	
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);

	}

	mesh->Render();

	if (mesh->textureID > 0) {
	
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}

void GameScene::RenderText(Mesh* mesh, std::string text, Colour colour) {

	if(!mesh || mesh->textureID <= 0) { //Proper error check

		return;

	}

	glDisable(GL_DEPTH_TEST);
	RenderTextWithDepth(mesh, text, colour);
	glEnable(GL_DEPTH_TEST);

}

void GameScene::RenderTextWithDepth(Mesh* mesh, std::string text, Colour colour) {

	if(!mesh || mesh->textureID <= 0) { //Proper error check

		return;

	}

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &colour.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	for(unsigned i = 0; i < text.length(); ++i) {

		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0.0f, 0.0f); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	
		mesh->Render((unsigned)text[i] * 6, 6);
	
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	
}

void GameScene::RenderTextOnScreen(Mesh* mesh, std::string text, Colour colour, float size, float x, float y) {

	if(!mesh || mesh->textureID <= 0) {//Proper error check
		return;
	}

	glDisable(GL_DEPTH_TEST);
	
	Mtx44 ortho;

	ortho.SetToOrtho(0, glfwGetVideoMode(glfwGetPrimaryMonitor())->width, 0, glfwGetVideoMode(glfwGetPrimaryMonitor())->height, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);

	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &colour.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	for(unsigned i = 0; i < text.length(); ++i) {

		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.3f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	
		mesh->Render((unsigned)text[i] * 6, 6);
	
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);

}

void GameScene::RenderObjectOnScreen(Mesh* mesh, float sizex,float sizey,float sizez, float x, float y, float z ,float rotate,float rx,float ry,float rz) {

	if (!mesh || mesh->textureID <= 0) {//Proper error check
		return;
	}

	glDisable(GL_DEPTH_TEST);

	Mtx44 ortho;
	ortho.SetToOrtho(0, glfwGetVideoMode(glfwGetPrimaryMonitor())->width, 0, glfwGetVideoMode(glfwGetPrimaryMonitor())->height, -10000, 100000); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);

	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack

	
	modelStack.Translate(x, y, 0);
	modelStack.Rotate(rotate,rx,ry,rz);
	modelStack.Scale(sizex, sizey, sizez);
	RenderMesh(mesh, false);

	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void GameScene::RenderObject(GameObject* object, bool enableLight) {

	if (!object->IsDisabled()) {

		modelStack.PushMatrix();
					
			modelStack.Translate(object->GetPosition().x, object->GetPosition().y, object->GetPosition().z);
			modelStack.MultMatrix(object->GetRotationMatrix());
			RenderMesh(object->GetMesh(), enableLight);

		modelStack.PopMatrix();

	}

}

void GameScene::RenderPlayerShip() {

	RenderObject(player->GetShip(), true);

	if (player->GetShip()->IsMining()) {
	
		modelStack.PushMatrix();

			modelStack.Translate(player->GetShip()->GetMiningLaser()->GetPosition().x, player->GetShip()->GetMiningLaser()->GetPosition().y, player->GetShip()->GetMiningLaser()->GetPosition().z);
			modelStack.MultMatrix(player->GetShip()->GetMiningLaser()->GetRotationMatrix());
			modelStack.Scale(1, 1, player->GetShip()->GetMiningLaser()->GetLength() + 30.0f);
			RenderMesh(player->GetShip()->GetMiningLaser()->GetMesh(), false);

		modelStack.PopMatrix();

	}

	for (list<Bullet>::iterator bullet_iter = (*player->GetShip()->GetBullets()).begin(); bullet_iter != (*player->GetShip()->GetBullets()).end(); ++bullet_iter) {
	
		RenderObject(&(*bullet_iter), false);

	}

}

void GameScene::RenderSpawnZones() {

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

				if (!asteroid_iter->IsDisabled()) {

					modelStack.PushMatrix();

					modelStack.Translate(asteroid_iter->GetPosition().x, asteroid_iter->GetPosition().y, asteroid_iter->GetPosition().z);
					modelStack.MultMatrix(asteroid_iter->GetRotationMatrix());
					float scale = asteroid_iter->GetRadius()/asteroid_iter->GetMaxRadius();
					modelStack.Scale(scale, scale, scale);
					RenderMesh(asteroid_iter->GetMesh(), true);

					modelStack.PopMatrix();

				}

			}

		}

	}

}

void GameScene::RenderInteractables() {

	for (std::list<Interactable*>::iterator it = iSpaceObjects.begin(); it != iSpaceObjects.end(); ++it) {
		
		modelStack.PushMatrix();
		modelStack.Translate((*it)->GetPosition().x, (*it)->GetPosition().y, (*it)->GetPosition().z);
		RenderMesh((*it)->GetMesh(), true);
		modelStack.PopMatrix();

	}

}

void GameScene::RenderSkybox() {

	modelStack.PushMatrix();

		modelStack.Translate(camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);

		float scaleSkybox = 6000.0f;

		for (GEOMETRY_TYPE i = SKYBOX_FRONT; i <= SKYBOX_RIGHT; i = static_cast<GEOMETRY_TYPE>(i + 1)) {

			modelStack.PushMatrix();

				modelStack.Rotate(90 * (i - SKYBOX_FRONT), 0, 1, 0);
				modelStack.Translate(scaleSkybox/2.0f - 1.0f, 0, 0);
				modelStack.Rotate(90, 0, 0, 1);
				modelStack.Rotate(90, 0, 1, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(mesh[i], false);

			modelStack.PopMatrix();

			modelStack.PushMatrix();

				modelStack.Translate(0, scaleSkybox/2.0f - 1.0f, 0);
				modelStack.Rotate(180, 1, 0, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(mesh[SKYBOX_TOP], false);

			modelStack.PopMatrix();

			modelStack.PushMatrix();

				modelStack.Translate(0, -scaleSkybox/2.0f + 1.0f, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(mesh[SKYBOX_BOTTOM], false);

			modelStack.PopMatrix();

		}

	modelStack.PopMatrix();

}

//Functions
void GameScene::BoundsChecking(GameObject* object, Vector3 boundarySize) {

	if (object->GetPosition().x > boundarySize.x/2.0f) {
	
		object->SetPosition(boundarySize.x/2.0f, object->GetPosition().y, object->GetPosition().z);

	}

	if (object->GetPosition().x < -boundarySize.x/2.0f) {
	
		object->SetPosition(-boundarySize.x/2.0f, object->GetPosition().y, object->GetPosition().z);

	}

	if (object->GetPosition().y > boundarySize.y/2.0f) {
	
		object->SetPosition(object->GetPosition().x, boundarySize.y/2.0f, object->GetPosition().z);

	}

	if (object->GetPosition().y < -boundarySize.y/2.0f) {
	
		object->SetPosition(object->GetPosition().x, -boundarySize.y/2.0f, object->GetPosition().z);

	}

	if (object->GetPosition().z > boundarySize.z/2.0f) {
	
		object->SetPosition(object->GetPosition().x, object->GetPosition().y, boundarySize.z/2.0f);

	}

	if (object->GetPosition().z < -boundarySize.z/2.0f) {
	
		object->SetPosition(object->GetPosition().x, object->GetPosition().y, -boundarySize.z/2.0f);

	}

}

void GameScene::BoundsChecking(GameObject* object, float radius) {

	if (object->GetPosition().Length() < 10.0f || radius < 10.0f) {
	
		return;

	}

	if (object->GetPosition().Length() > radius) {
	
		object->SetPosition(object->GetPosition().Normalized() * radius);

	}

}
//Setters
void GameScene::SetSkybox(const char* topTexture, const char* bottomTexture, const char* frontTexture, const char* leftTexture, const char* backTexture, const char* rightTexture) {

	mesh[SKYBOX_TOP]->textureID = LoadTGA(topTexture);
	mesh[SKYBOX_BOTTOM]->textureID = LoadTGA(bottomTexture);
	mesh[SKYBOX_FRONT]->textureID = LoadTGA(frontTexture);
	mesh[SKYBOX_LEFT]->textureID = LoadTGA(leftTexture);
	mesh[SKYBOX_BACK]->textureID = LoadTGA(backTexture);
	mesh[SKYBOX_RIGHT]->textureID = LoadTGA(rightTexture);

}
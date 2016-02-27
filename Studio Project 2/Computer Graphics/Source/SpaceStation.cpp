/*#include "SpaceStation.h"

SpaceStation::SpaceStation() {
}

SpaceStation::~SpaceStation() {
}

void SpaceStation::Init() { //Initialise Vertex Buffer Object (VBO) here.

	//Set the background colour to dark blue.
	glClearColor(0.2f, 0.0f, 0.25f, 0.0f);

	Mtx44 projection;
	
	projection.SetToPerspective(75.0f, (float)(glfwGetVideoMode(glfwGetPrimaryMonitor())->width)/(glfwGetVideoMode(glfwGetPrimaryMonitor())->height), 0.1f, 1000.0f); //FOV, Aspect Ratio, Near Plane, Far Plane.
	projectionStack.LoadMatrix(projection);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	
	light[0].type = Light::LIGHT_SPOT;
	light[0].colour.Set(1.0f, 1.0f, 0.82f);
	light[0].power = 0.0;
	light[0].kC = 1.0f;
	light[0].kL = 0.1f;
	light[0].kQ = 0.02f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(50));
	light[0].cosInner = cos(Math::DegreeToRadian(37));
	light[0].exponent = 3.0f;
	light[0].position.Set(0, 20, 0);
	light[0].spotDirection.Set(0.0f, 0.0f, 1.0f);

	light[1].type = Light::LIGHT_DIRECTIONAL;
	light[1].position.Set(-20, 100, -15);
	light[1].colour.Set(1, 1, 1);
	light[1].power = 1.0f;
	light[1].kC = 0.1f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	light[1].cosInner = cos(Math::DegreeToRadian(30));
	light[1].exponent = 3.0f;
	light[1].spotDirection.Set(0.0f, -1.0f, 1.0f);


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

	//Light 0 (Spotlight)
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
	
	//Light 1 (Directional Light)
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	//Make sure you pass uniform parameters after glUseProgram().
	glUniform1i(m_parameters[U_NUMLIGHTS], 2);
	
	//Light 0 (Spotlight)
	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].colour.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	//Light 1 (Directional)
	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].colour.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);
	
	//Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	//Enable Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Initialise Camera
	camera.Init(Vector3(30, 2, -17), Vector3(30, 2, -18));

	//Axes
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes();
	
	//Skybox
	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("Skybox Front", Colour(1, 1, 1), 1.0f);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//Skybox//Front.tga");
	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("Skybox Back", Colour(1, 1, 1), 1.0f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//Skybox//Back.tga");
	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("Skybox Left", Colour(1, 1, 1), 1.0f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//Skybox//Left.tga");
	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("Skybox Right", Colour(1, 1, 1), 1.0f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//Skybox//Right.tga");
	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("Skybox Top", Colour(1, 1, 1), 1.0f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//Skybox//Top.tga");
	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("Skybox Bottom", Colour(1, 1, 1), 1.0f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//Skybox//Bottom.tga");

	//SpaceStation
	meshList[GEO_MODEL_HANGAR] = MeshBuilder::GenerateOBJ("Hangar", "OBJ//Space_Station//Hangar.obj");
	meshList[GEO_MODEL_HANGAR]->textureID = LoadTGA("Image//Space_Station//Hangar.tga");
	meshList[GEO_MODEL_HANGAR]->material = MaterialList::GetInstance()->material[MaterialList::METAL];

	//Text
	meshList[GEO_TEXT] = MeshBuilder::GenerateText("Text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//Fonts//Consolas.tga");

	meshList[GEO_LIGHT_BALL] = MeshBuilder::GenerateSphere("Light Ball", Colour(1, 1, 1), 20, 20, 0.3f);

	//NPCs
	npcs[TECK_LEE] = NPC("Teck Lee", Vector3(-32, 0, -6), Vector3(0, 0, 0), NPC::QUEST_GIVER, "Image//NPC//Teck_Lee.tga");
	npcs[TECK_LING] = NPC("Teck Ling", Vector3(-7, 0, -6), Vector3(0, 0, 0), NPC::QUEST_GIVER, "Image//NPC//Teck_Ling.tga");
	npcs[REYNARD] = NPC("Reynard", Vector3(15, 0, 0), Vector3(0, 0, 0), NPC::MECHANIC, "Image//NPC//Reynard.tga");
	npcs[TERRY] = NPC("Terry", Vector3(-18, 0, 15), Vector3(0, 0, 0), NPC::MECHANIC, "Image//NPC//Terry.tga");
	npcs[DANIEL] = NPC("Daniel", Vector3(-36, 0, 17), Vector3(0, -60, 0), NPC::OMBER_BUYER, "Image//NPC//Daniel.tga");
	npcs[KEITH] = NPC("Keith", Vector3(-36, 0, 11), Vector3(0, 60, 0), NPC::VELDSPAR_BUYER, "Image//NPC//Keith.tga");
	npcs[VICTOR] = NPC("Victor", Vector3(0, 0, 15), Vector3(0, 90, 0), NPC::KERNITE_BUYER, "Image//NPC//Victor.tga");
	npcs[BENNY] = NPC("Benny", Vector3(25, 0, 0), Vector3(0, 0, 0), NPC::CO_PILOT, "Image//NPC//Benny.tga");
	npcs[HAO_MING] = NPC("Hao Ming", Vector3(27, 0, 16), Vector3(0, 90, 0), NPC::BY_STANDER, "Image//NPC//Hao_Ming.tga");
	npcs[SEK_HENG] = NPC("Sek Heng", Vector3(28, 0, 16), Vector3(0, 90, 0), NPC::MECHANIC, "Image//NPC//Sek_Heng.tga");

	//OBJ collision
	objs.push_back( CollideObj("Blue Freighter",Vector3(0, 4,-5), Vector3(10, 8, 20),"OBJ//Freighter//Freighter.obj","Image///Freighter//Freighter_Blue.tga",MaterialList::GetInstance()->material[MaterialList::METAL]) );
	objs.push_back( CollideObj("Red Freighter", Vector3(-25, 4, -5), Vector3(10, 8, 20), "OBJ//Freighter//Freighter.obj", "Image///Freighter//Freighter_Red.tga", MaterialList::GetInstance()->material[MaterialList::METAL]) );
	objs.push_back( CollideObj("Avalanche", Vector3(-15,1,15), Vector3(6, 8, 3), "OBJ//Avalanche//Avalanche.obj", "Image///Avalanche//Avalanche.tga", MaterialList::GetInstance()->material[MaterialList::METAL]));


	camera.InitObj(objs);
	
	//Initialise Variables
	playerState = START_MENU;
	menuOption = START;

	ScreenMidX = (glfwGetVideoMode(glfwGetPrimaryMonitor())->width)/2;
	ScreenMidY = (glfwGetVideoMode(glfwGetPrimaryMonitor())->height)/2;
	PlayerShip::GetInstance()->rotationOrientation.SetToIdentity();
	PlayerShip::GetInstance()->position = Vector3(20, 3, -3);
	pause = false;

}

void SpaceStation::Update(double dt) {

	CheckKeyPress();

	if (Application::IsKeyPressed('1')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	} else if (Application::IsKeyPressed('2')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	frameRate = 1.0/dt;

	boundsChecking(&camera.position);

	if (playerState == START_MENU) {

		UpdateStartMenu();

	} else if (playerState == PLAYING) {

		camera.Update(dt);

		if (Application::IsKeyPressed(VK_ESCAPE)) {

			playerState = START_MENU;
			pause = true;

		}

	} else if (playerState == QUEST_MENU) {
	
		UpdateQuests(questGiverName);

	} else if (playerState == SHOP_MENU) {
	
		UpdateShop(shopKeeperName);

	} else if (playerState == LEAVING_STATION) {
	
		PlayLeavingAnimation(dt);
		camera.position = Vector3(30, 2, -17);
		camera.target = PlayerShip::GetInstance()->GetPosition();

	}

	if (Application::IsKeyPressed('E') && !isPressed[E] && (playerState == QUEST_MENU || playerState == SHOP_MENU)) {
		
		isPressed[E] = true;

		playerState = PLAYING;

	}

}

void SpaceStation::PlayLeavingAnimation(double &dt) {

	if (PlayerShip::GetInstance()->GetPosition().y <= 10.0f) {
	
		PlayerShip::GetInstance()->Translate(0, 4.0f * dt, 0);

	} else if (PlayerShip::GetInstance()->GetPosition().z <= 40.0f) {
	
		PlayerShip::GetInstance()->Translate(0, 0, 20.0f * dt);

	} else {
	
		SharedData::GetInstance()->sceneNumber = 2;

	}

}

void SpaceStation::UpdateQuests(string giver) {

	//Checks if there are any suitable quests
	if (QuestSystem::GetInstance()->selectedQuest == QuestSystem::GetInstance()->quests.end()) {

		for (list<Quest>::iterator iter = QuestSystem::GetInstance()->quests.begin(); iter != QuestSystem::GetInstance()->quests.end(); ++iter) {
		
			if (iter->isActive || (iter->giver == giver && !iter->isComplete)) {
			
				QuestSystem::GetInstance()->selectedQuest = iter; //Suitable quest found. Break the loop.
				break;

			}

			if (std::next(iter) == QuestSystem::GetInstance()->quests.end()) { //We've reached the end of the loop but still have not found any suitable quests.
			
				return;

			}

		}

	}

	if (Application::IsKeyPressed(VK_LEFT)) {
	
		for (list<Quest>::iterator iter = QuestSystem::GetInstance()->quests.begin(); iter != QuestSystem::GetInstance()->quests.end(); ++iter) {
		
			if (iter->isActive || (iter->giver == giver && !iter->isComplete)) {
			
				QuestSystem::GetInstance()->selectedQuest = iter;
				break;

			}

		}

	} else if (Application::IsKeyPressed(VK_RIGHT)) {
	
		for (list<Quest>::iterator iter = QuestSystem::GetInstance()->quests.begin(); iter != QuestSystem::GetInstance()->quests.end(); ++iter) {
		
			if (iter->giver == giver && !iter->isComplete && !iter->isActive) {
			
				QuestSystem::GetInstance()->selectedQuest = iter;
				break;

			}

		}

	} else if (Application::IsKeyPressed(VK_DOWN) && !isPressed[DOWN]) {
	
		isPressed[DOWN] = true;

		if (QuestSystem::GetInstance()->selectedQuest->isActive) {
		
			if (std::next(QuestSystem::GetInstance()->selectedQuest) != QuestSystem::GetInstance()->quests.end() && std::next(QuestSystem::GetInstance()->selectedQuest)->isActive) {
			
				++QuestSystem::GetInstance()->selectedQuest;

			}

		} else {

			for (list<Quest>::iterator iter = QuestSystem::GetInstance()->selectedQuest; iter != QuestSystem::GetInstance()->quests.end(); ++iter) {
		
				if (iter != QuestSystem::GetInstance()->selectedQuest && iter->giver == giver && !iter->isComplete && !iter->isActive) {
			
					QuestSystem::GetInstance()->selectedQuest = iter;
					break;

				}

			}
		
		}

	} else if (Application::IsKeyPressed(VK_UP) && !isPressed[UP]) {
	
		isPressed[UP] = true;

		if (QuestSystem::GetInstance()->selectedQuest->isActive) {
		
			if (QuestSystem::GetInstance()->selectedQuest != QuestSystem::GetInstance()->quests.begin()) {
			
				--QuestSystem::GetInstance()->selectedQuest;

			}

		} else {
		
			for (list<Quest>::iterator iter = QuestSystem::GetInstance()->selectedQuest;; --iter) {

				if (iter != QuestSystem::GetInstance()->selectedQuest && !iter->isActive && !iter->isComplete && iter->giver == giver) {

					QuestSystem::GetInstance()->selectedQuest = iter;
					break;

				}

				if (iter == QuestSystem::GetInstance()->quests.begin()) {
						
					break;

				}

			}

		}

	} else if (Application::IsKeyPressed(VK_RETURN) && !isPressed[RETURN]) {
	
		isPressed[RETURN] = true;

		if (QuestSystem::GetInstance()->selectedQuest->isActive && QuestSystem::GetInstance()->selectedQuest->isComplete && QuestSystem::GetInstance()->selectedQuest->giver == giver) {
		
			QuestSystem::GetInstance()->selectedQuest->HandIn();
			Quest quest = *QuestSystem::GetInstance()->selectedQuest;
			QuestSystem::GetInstance()->quests.remove(*QuestSystem::GetInstance()->selectedQuest);
			QuestSystem::GetInstance()->quests.push_back(quest);
			QuestSystem::GetInstance()->selectedQuest = QuestSystem::GetInstance()->quests.end();

		} else if (!QuestSystem::GetInstance()->selectedQuest->isActive && !QuestSystem::GetInstance()->selectedQuest->isComplete) {
		
			QuestSystem::GetInstance()->selectedQuest->PickUp();
			Quest quest = *QuestSystem::GetInstance()->selectedQuest;
			QuestSystem::GetInstance()->quests.remove(*QuestSystem::GetInstance()->selectedQuest);
			QuestSystem::GetInstance()->quests.push_front(quest);
			QuestSystem::GetInstance()->selectedQuest = QuestSystem::GetInstance()->quests.end();


		}

	} else if (Application::IsKeyPressed(VK_BACK) && !isPressed[BACK]) {
	
		isPressed[BACK] = true;

		if (QuestSystem::GetInstance()->selectedQuest->isActive && !QuestSystem::GetInstance()->selectedQuest->isComplete) {
		
			QuestSystem::GetInstance()->selectedQuest->Cancel();
			Quest quest = *QuestSystem::GetInstance()->selectedQuest;
			QuestSystem::GetInstance()->quests.remove(*QuestSystem::GetInstance()->selectedQuest);
			QuestSystem::GetInstance()->quests.push_back(quest);
			QuestSystem::GetInstance()->selectedQuest = QuestSystem::GetInstance()->quests.end();

		}

	}

}

void SpaceStation::UpdateShop(string seller) {

	if (ShopSystem::GetInstance()->selectedUpgrade == ShopSystem::GetInstance()->upgrades.end()) {
	
		for (list<Upgrade>::iterator iter = ShopSystem::GetInstance()->upgrades.begin(); iter != ShopSystem::GetInstance()->upgrades.end(); ++iter) {

			if (iter->seller == seller) {
			
				ShopSystem::GetInstance()->selectedUpgrade = iter;
				break;

			}

		}

		if (ShopSystem::GetInstance()->selectedUpgrade == ShopSystem::GetInstance()->upgrades.end()) {
			return;

		}

	}

	if (Application::IsKeyPressed(VK_DOWN) && !isPressed[DOWN]) {
	
		isPressed[DOWN] = true;

		for (list<Upgrade>::iterator iter = ShopSystem::GetInstance()->selectedUpgrade; iter != ShopSystem::GetInstance()->upgrades.end(); ++iter) {
		
			if (iter != ShopSystem::GetInstance()->selectedUpgrade && iter->seller == seller) {
			
				ShopSystem::GetInstance()->selectedUpgrade = iter;
				break;

			}

		}

	} else if (Application::IsKeyPressed(VK_UP) && !isPressed[UP]) {
	
		isPressed[UP] = true;

		for (list<Upgrade>::iterator iter = ShopSystem::GetInstance()->selectedUpgrade;; --iter) {
		
			if (iter != ShopSystem::GetInstance()->selectedUpgrade && iter->seller == seller) {
			
				ShopSystem::GetInstance()->selectedUpgrade = iter;
				break;

			}

			if (iter == ShopSystem::GetInstance()->upgrades.begin()) {
			
				break;

			}

		}

	} else if (Application::IsKeyPressed(VK_RETURN) && !isPressed[RETURN]) {
	
		isPressed[RETURN] = true;

		if (ShopSystem::GetInstance()->selectedUpgrade->cost <= Inventory::GetInstance()->gold) {
		
			if (PlayerShip::GetInstance()->upgrades[ShopSystem::GetInstance()->selectedUpgrade->upgradeType] != nullptr) {
			
				Inventory::GetInstance()->gold += PlayerShip::GetInstance()->upgrades[ShopSystem::GetInstance()->selectedUpgrade->upgradeType]->cost;

			}

			Inventory::GetInstance()->gold -= ShopSystem::GetInstance()->selectedUpgrade->cost;
			PlayerShip::GetInstance()->upgrades[ShopSystem::GetInstance()->selectedUpgrade->upgradeType] = &(*ShopSystem::GetInstance()->selectedUpgrade);
			PlayerShip::GetInstance()->UpdateStats();

		}

	}

}

void SpaceStation::UpdateStartMenu() {

	if (!isPressed[UP] && Application::IsKeyPressed(VK_UP)) {
		
		isPressed[UP] = true;

		if (menuOption != START) {
		
			menuOption = static_cast<MENU_OPTION>(menuOption - 1);

		}
	
	}

	if (!isPressed[DOWN] && Application::IsKeyPressed(VK_DOWN)) {
	
		isPressed[DOWN] = true;

		if (menuOption != QUIT) {
		
			menuOption = static_cast<MENU_OPTION>(menuOption + 1);

		}

	}

	if (Application::IsKeyPressed(VK_RETURN) && !isPressed[RETURN]) {
	
		isPressed[RETURN] = true;

		if (menuOption == START) {
		
			playerState = PLAYING;

		} else if (menuOption == SOUND) {

			if (SharedData::GetInstance()->soundOn == true) {
			
				SharedData::GetInstance()->soundOn = false;

			} else if (SharedData::GetInstance()->soundOn == false) {
			
				SharedData::GetInstance()->soundOn = true;

			}

		} else if (menuOption == QUIT) {
		
			SharedData::GetInstance()->quitGame = true;

		}

	}

}

void SpaceStation::CheckKeyPress() {

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

void SpaceStation::npcInteraction() {

	Colour textColour = Colour(1.0f, 0.0f, 0.0f);
	float textSize = 70.0f;
	int posX = 5;
	int posY = 5;

	for (int i = 0; i < NUM_NPC && playerState == PLAYING; ++i) {

		if (Physics::getDistance(camera.position, npcs[i].getPosition()) <= 3.0f) {

			if (npcs[i].getType() == NPC::CO_PILOT) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to talk to " + npcs[i].getName() + " to exit the hangar.", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					playerState = LEAVING_STATION;

				}

			} else if (npcs[i].getType() == NPC::MECHANIC) {
		
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to talk to " + npcs[i].getName() + ".", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					ShopSystem::GetInstance()->selectedUpgrade = ShopSystem::GetInstance()->upgrades.end();
					shopKeeperName = npcs[i].getName();
					playerState = SHOP_MENU;

				}

				break;

			} else if (npcs[i].getType() == NPC::QUEST_GIVER) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to talk to " + npcs[i].getName() + ".", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					QuestSystem::GetInstance()->selectedQuest = QuestSystem::GetInstance()->quests.end();
					questGiverName = npcs[i].getName();
					playerState = QUEST_MENU;

				}

				break;

			} else if (npcs[i].getType() == NPC::KERNITE_BUYER) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to sell your Kernite to " + npcs[i].getName() + ".", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					Inventory::GetInstance()->gold += Inventory::GetInstance()->kernite * 10;
					Inventory::GetInstance()->kernite = 0;

				}

				break;

			} else if (npcs[i].getType() == NPC::OMBER_BUYER) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to sell your Omber to " + npcs[i].getName() + ".", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					Inventory::GetInstance()->gold += Inventory::GetInstance()->omber * 5;
					Inventory::GetInstance()->omber = 0;

				}

				break;

			} else if (npcs[i].getType() == NPC::VELDSPAR_BUYER) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], "Press E to sell your Veldspar to " + npcs[i].getName() + ".", textColour, textSize, posX, posY);

				if (Application::IsKeyPressed('E') && !isPressed[E]) {
				
					isPressed[E] = true;

					Inventory::GetInstance()->gold += Inventory::GetInstance()->veldspar * 2;
					Inventory::GetInstance()->veldspar = 0;

				}

				break;

			}

		}

	}

}

void SpaceStation::Render() { //Render VBO here.

	//Clear colour & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);

	//Spotlight Light
	light[0].position.Set(camera.position.x, camera.position.y, camera.position.z);
	light[0].spotDirection = -camera.view;

	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
	glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);

	//Directional Light
	Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
	Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
	glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);

	modelStack.LoadIdentity();

	modelStack.PushMatrix();
		
		modelStack.Translate(light[1].position.x, light[1].position.y, light[1].position.z);
		RenderMesh(meshList[GEO_LIGHT_BALL], false);

	modelStack.PopMatrix();

	RenderSkybox();
	RenderObjects();
	RenderShip();
	RenderNPC();
	RenderFPS();

	npcInteraction();

	if (playerState == START_MENU) {
	
		RenderStartMenu();                           

	} else if (playerState == PLAYING) {
		
		RenderInventory();

	} else if (playerState == QUEST_MENU) {
	
		RenderQuests(questGiverName);
		RenderInventory();

	} else if (playerState == SHOP_MENU) {
	
		RenderShop(shopKeeperName);
		RenderInventory();

	}

}

void SpaceStation::RenderNPC() {

	for (unsigned int i = 0; i < NUM_NPC; ++i) {
	
		modelStack.PushMatrix();

			modelStack.Translate(npcs[i].getPosition().x, npcs[i].getPosition().y, npcs[i].getPosition().z);

			modelStack.PushMatrix();

				modelStack.Rotate(npcs[i].getRotation().y, 0, 1, 0);
				
				modelStack.PushMatrix();

					modelStack.Translate(0, 1.4, 0);
					RenderMesh(npcs[i].mesh[NPC::BODY], true);

					modelStack.PushMatrix();

						modelStack.Translate(0, 0.4, 0);

						modelStack.PushMatrix();

							modelStack.Rotate(npcs[i].bodyRotation[NPC::HEAD].y, 0, 1, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::HEAD].x, 1, 0, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::HEAD].z, 0, 0, 1);
							RenderMesh(npcs[i].mesh[NPC::HEAD], true);

						modelStack.PopMatrix();

					modelStack.PopMatrix();

					modelStack.PushMatrix();

						modelStack.Translate(-0.2, 0.4, 0);

						modelStack.PushMatrix();

							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_ARM].y, 0, 1, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_ARM].x, 1, 0, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_ARM].z, 0, 0, 1);
							RenderMesh(npcs[i].mesh[NPC::RIGHT_ARM], true);

						modelStack.PopMatrix();

					modelStack.PopMatrix();

					modelStack.PushMatrix();

						modelStack.Translate(0.2, 0.4, 0);

						modelStack.PushMatrix();

							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_ARM].y, 0, 1, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_ARM].x, 1, 0, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_ARM].z, 0, 0, 1);
							RenderMesh(npcs[i].mesh[NPC::LEFT_ARM], true);

						modelStack.PopMatrix();

					modelStack.PopMatrix();

					modelStack.PushMatrix();

						modelStack.Translate(0.1, 0, 0);

						modelStack.PushMatrix();

							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_LEG].y, 0, 1, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_LEG].x, 1, 0, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::LEFT_LEG].z, 0, 0, 1);
							RenderMesh(npcs[i].mesh[NPC::LEFT_LEG], true);

						modelStack.PopMatrix();

					modelStack.PopMatrix();

					modelStack.PushMatrix();

						modelStack.Translate(-0.1, 0, 0);

						modelStack.PushMatrix();

							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_LEG].y, 0, 1, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_LEG].x, 1, 0, 0);
							modelStack.Rotate(npcs[i].bodyRotation[NPC::RIGHT_LEG].z, 0, 0, 1);
							RenderMesh(npcs[i].mesh[NPC::RIGHT_LEG], true);

						modelStack.PopMatrix();

					modelStack.PopMatrix();

				modelStack.PopMatrix();

			modelStack.PopMatrix();

		modelStack.PopMatrix();

	}

}

void SpaceStation::RenderShop(string seller) {

	float equippedPosX = 5.0f;
	float forSalePosX = 15.0f;
	float forSalePosY = 12.0f;
	float textSize = 70.0f;
	Colour textColour(1.0f, 0.0f, 0.0f);

	RenderTextOnScreen(meshList[GEO_TEXT], "Equipped Upgrades", textColour, textSize, 5.0, 14.0f);
	RenderTextOnScreen(meshList[GEO_TEXT], "Armour:", textColour, textSize, 5.0, 12.0f);
	RenderTextOnScreen(meshList[GEO_TEXT], "Weapon:", textColour, textSize, 5.0, 10.0f);
	RenderTextOnScreen(meshList[GEO_TEXT], "Engine:", textColour, textSize, 5.0, 8.0f);
	RenderTextOnScreen(meshList[GEO_TEXT], "For Sale", textColour, textSize, 15.0f, 14.0f);
	
	if (PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR] != nullptr) {
	
		RenderTextOnScreen(meshList[GEO_TEXT], PlayerShip::GetInstance()->upgrades[Upgrade::ARMOUR]->name, textColour, textSize, 5.0f, 11.0f);

	}

	if (PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON] != nullptr) {
	
		RenderTextOnScreen(meshList[GEO_TEXT], PlayerShip::GetInstance()->upgrades[Upgrade::WEAPON]->name, textColour, textSize, 5.0f, 9.0f);

	}

	if (PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE] != nullptr) {
	
		RenderTextOnScreen(meshList[GEO_TEXT], PlayerShip::GetInstance()->upgrades[Upgrade::ENGINE]->name, textColour, textSize, 5.0f, 7.0f);

	}

	for (list<Upgrade>::iterator iter = ShopSystem::GetInstance()->upgrades.begin(); iter != ShopSystem::GetInstance()->upgrades.end(); ++iter) {
	
		if (iter->seller == seller) {

			RenderTextOnScreen(meshList[GEO_TEXT], iter->name, textColour, textSize, forSalePosX, forSalePosY);

			if (ShopSystem::GetInstance()->selectedUpgrade == iter) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, forSalePosX - 1.0f, forSalePosY);

			}

			--forSalePosY;

		}

	}

	if (ShopSystem::GetInstance()->selectedUpgrade != ShopSystem::GetInstance()->upgrades.end()) {
	
		RenderTextOnScreen(meshList[GEO_TEXT], "Description: " + ShopSystem::GetInstance()->selectedUpgrade->description, textColour, textSize, equippedPosX, 5.0f);
		RenderTextOnScreen(meshList[GEO_TEXT], "Cost: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->cost) + " Gold", textColour, textSize, equippedPosX, 4.0f);
		
		if (ShopSystem::GetInstance()->selectedUpgrade->upgradeType == Upgrade::WEAPON) {
		
			RenderTextOnScreen(meshList[GEO_TEXT], "Damage: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->damage), textColour, textSize, equippedPosX, 3.0f);
			RenderTextOnScreen(meshList[GEO_TEXT], "Fire Rate: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->fireRate), textColour, textSize, equippedPosX, 2.0f);

		} else if (ShopSystem::GetInstance()->selectedUpgrade->upgradeType == Upgrade::ARMOUR) {
		
			RenderTextOnScreen(meshList[GEO_TEXT], "Armour: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->armour), textColour, textSize, equippedPosX, 3.0f);
			
		} else if (ShopSystem::GetInstance()->selectedUpgrade->upgradeType == Upgrade::ENGINE) {
	
			RenderTextOnScreen(meshList[GEO_TEXT], "Fuel: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->damage), textColour, textSize, equippedPosX, 3.0f);
			RenderTextOnScreen(meshList[GEO_TEXT], "Speed: " + std::to_string(ShopSystem::GetInstance()->selectedUpgrade->speed), textColour, textSize, equippedPosX, 2.0f);

		}

	}

}

void SpaceStation::RenderQuests(string giver) {

	float activePosX = 5.0f;
	float inactivePosX = 15.0f;
	float activePosY = 10.0f;
	float inactivePosY = 10.0f;
	float textSize = 70.0f;
	Colour textColour(1.0f, 0.0f, 0.0f);

	RenderTextOnScreen(meshList[GEO_TEXT], "Active Quest", textColour, textSize, activePosX, activePosY + 2.0f);
	RenderTextOnScreen(meshList[GEO_TEXT], "Available Quest", textColour, textSize, inactivePosX, inactivePosY + 2.0f);

	if (QuestSystem::GetInstance()->selectedQuest != QuestSystem::GetInstance()->quests.end() && QuestSystem::GetInstance()->selectedQuest != QuestSystem::GetInstance()->quests.end()) {
	
		RenderTextOnScreen(meshList[GEO_TEXT], "Quest Giver: " + QuestSystem::GetInstance()->selectedQuest->giver, textColour, textSize, activePosX, 5.0f);
		RenderTextOnScreen(meshList[GEO_TEXT], "Description: " + QuestSystem::GetInstance()->selectedQuest->description, textColour, textSize, activePosX, 4.0f);
		RenderTextOnScreen(meshList[GEO_TEXT], "Reward: " + std::to_string(QuestSystem::GetInstance()->selectedQuest->reward) + " Gold", textColour, textSize, activePosX, 3.0f);
		RenderTextOnScreen(meshList[GEO_TEXT], "Progress: " + std::to_string(QuestSystem::GetInstance()->selectedQuest->current) + "/" + std::to_string(QuestSystem::GetInstance()->selectedQuest->target), textColour, textSize, activePosX, 2.0f);

	}

	for (list<Quest>::iterator iter = QuestSystem::GetInstance()->quests.begin(); iter != QuestSystem::GetInstance()->quests.end(); ++iter) {
	
		if (iter->isActive) {
		
			if (!iter->isComplete) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], iter->name, textColour, textSize, activePosX, activePosY);

			} else {
				
				RenderTextOnScreen(meshList[GEO_TEXT], iter->name, Colour(0.0f, 1.0f, 1.0f), textSize, activePosX, activePosY);
			
			}

			if (iter == QuestSystem::GetInstance()->selectedQuest) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, activePosX - 1.0f, activePosY);

			}

			--activePosY;

		} else if (iter->giver == giver && !iter->isComplete) {
		
			RenderTextOnScreen(meshList[GEO_TEXT], iter->name, textColour, textSize, inactivePosX, inactivePosY);

			if (iter == QuestSystem::GetInstance()->selectedQuest) {
			
				RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, inactivePosX - 1.0f, inactivePosY);

			}

			--inactivePosY;

		}

	}

}

void SpaceStation::RenderShip() {

	modelStack.PushMatrix();

		modelStack.Translate(PlayerShip::GetInstance()->GetPosition().x, PlayerShip::GetInstance()->GetPosition().y, PlayerShip::GetInstance()->GetPosition().z);

		modelStack.PushMatrix();

			modelStack.MultMatrix(PlayerShip::GetInstance()->GetRotationMatrix());
			RenderMesh(PlayerShip::GetInstance()->GetMesh(), true);

		modelStack.PopMatrix();

	modelStack.PopMatrix();

}

void SpaceStation::RenderMesh(Mesh *mesh, bool enableLight) {

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

void SpaceStation::RenderSkybox() {

	modelStack.PushMatrix();

		modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);

		int scaleSkybox = 1000;

		for (int i = GEO_FRONT; i <= GEO_RIGHT; ++i) {

			modelStack.PushMatrix();

				modelStack.Rotate(90 * (i - GEO_FRONT), 0, 1, 0);
				modelStack.Translate(scaleSkybox/2 - 1, 0, 0);
				modelStack.Rotate(90, 0, 0, 1);
				modelStack.Rotate(90, 0, 1, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(meshList[i], false);

			modelStack.PopMatrix();

			modelStack.PushMatrix();

				modelStack.Translate(0, scaleSkybox/2 - 1, 0);
				modelStack.Rotate(180, 1, 0, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(meshList[GEO_TOP], false);

			modelStack.PopMatrix();

			modelStack.PushMatrix();

				modelStack.Translate(0, -scaleSkybox/2 + 1, 0);
				modelStack.Scale(scaleSkybox, 1, scaleSkybox);
				RenderMesh(meshList[GEO_BOTTOM], false);

			modelStack.PopMatrix();

		}

	modelStack.PopMatrix();

}

void SpaceStation::RenderText(Mesh* mesh, std::string text, Colour colour) {

	if(!mesh || mesh->textureID <= 0) { //Proper error check

		return;

	}

	glDisable(GL_DEPTH_TEST);
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
	glEnable(GL_DEPTH_TEST);
	
}

void SpaceStation::RenderTextWithDepth(Mesh* mesh, std::string text, Colour colour) {

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
		characterSpacing.SetToTranslation(i * 0.5f, 0.0f, 0.0f); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	
		mesh->Render((unsigned)text[i] * 6, 6);
	
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	
}

void SpaceStation::RenderTextOnScreen(Mesh* mesh, string text, Colour colour, float size, float x, float y) {

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

void SpaceStation::RenderObjectOnScreen(Mesh* mesh, float size, float x, float y)
{
	if (!mesh || mesh->textureID <= 0) {//Proper error check
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
	RenderMesh(mesh,true);

	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void SpaceStation::RenderStartMenu()
{

	Colour textColour = Colour(1.0f, 0.0f, 0.0f);
	float textSize = 100.0f;
	float posX = 8.7f;
	float posY = 6.0f;

	if (menuOption == START)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, posX - 1.0f, posY);
	}
	else if (menuOption == SOUND)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, posX - 1.0f, posY - 1.0f);
	}
	else if (menuOption == QUIT)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], ">", textColour, textSize, posX - 1.0f, posY - 2.0f);
	}

	if (playerState == START_MENU)
	{
		if (pause)
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "CONTINUE", textColour, textSize, posX, posY);
		}
		else
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "START", textColour, textSize, posX, posY);
		}
		RenderTextOnScreen(meshList[GEO_TEXT], "SOUND", textColour, textSize, posX, posY - 1.0f);

		RenderTextOnScreen(meshList[GEO_TEXT], "QUIT", textColour, textSize, posX, posY - 2.0f);

		RenderTextOnScreen(meshList[GEO_TEXT], "Press Enter to select.", textColour, textSize, 6.5f, posY - 4.0f);

	}

}

void SpaceStation::RenderInventory() {

	Colour textColour = Colour(1.0f, 0.0f, 0.0f);
	float posX = 22.0f;
	float posY = 5.0f;

	//Gold
	RenderTextOnScreen(meshList[GEO_TEXT], "Gold: " + std::to_string(Inventory::GetInstance()->gold), textColour, 70.0f, posX, posY);
	//Veldspar
	RenderTextOnScreen(meshList[GEO_TEXT], "Veldspar: " + std::to_string(Inventory::GetInstance()->veldspar), textColour, 70.0f, posX, posY - 1.0f);
	//Omber
	RenderTextOnScreen(meshList[GEO_TEXT],"Omber: " + std::to_string(Inventory::GetInstance()->omber), textColour, 70.0f, posX, posY - 2.0f);
	//Kernite
	RenderTextOnScreen(meshList[GEO_TEXT], "Kernite: " + std::to_string(Inventory::GetInstance()->kernite), textColour, 70.0f, posX, posY - 3.0f);

}

void SpaceStation::RenderFPS() {

	RenderTextOnScreen(meshList[GEO_TEXT], "FPS: " + std::to_string((int)frameRate), Colour(0.0f, 1.0f, 1.0f), 50, 36, 21);

}

void SpaceStation::RenderObjects() {

	modelStack.PushMatrix();
	modelStack.Scale(4,4,4);
	RenderMesh(meshList[GEO_MODEL_HANGAR], true);
	modelStack.PopMatrix();

	for (vector<CollideObj>::iterator iter = objs.begin(); iter != objs.end(); ++iter) {

		modelStack.PushMatrix();

			modelStack.Translate(iter->position.x, iter->position.y, iter->position.z);
			RenderMesh(iter->mesh, true);

		modelStack.PopMatrix();

	}

}

void SpaceStation::boundsChecking(Vector3* position) {

	int xLimit = 39;
	int zLimit = 19;

	if (position->x > xLimit) {
	
		position->x = xLimit;

	} else if (position->x < -xLimit) {
	
		position->x = -xLimit;

	}

	if (position->z > zLimit) {
	
		position->z = zLimit;

	} else if (position->z < -zLimit) {
	
		position->z = -zLimit;

	}

}

void SpaceStation::Exit() {

	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);

}*/
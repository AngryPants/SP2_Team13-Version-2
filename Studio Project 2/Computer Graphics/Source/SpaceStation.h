//#ifndef _SPACESTATION_H
//#define _SPACESTATION_H
//
//#include "GameScene.h"
//
//class SpaceStation : public GameScene {
//
//public:
//	enum GEOMETRY_TYPE {
//		
//		GEO_AXES = 0,
//
//		//Skybox
//		GEO_TOP,
//		GEO_BOTTOM,
//		GEO_FRONT,
//		GEO_LEFT,
//		GEO_BACK,
//		GEO_RIGHT,
//
//		//Text
//		GEO_TEXT,
//		
//		//Space Station
//		GEO_MODEL_HANGAR,
//
//		//Lights
//		GEO_LIGHT_BALL,
//
//		NUM_GEOMETRY,
//
//	};
//
//	enum UNIFORM_TYPE {
//		
//		U_MVP = 0,
//		U_MODELVIEW,
//		U_MODELVIEW_INVERSE_TRANSPOSE,
//		U_MATERIAL_AMBIENT,
//		U_MATERIAL_DIFFUSE,
//		U_MATERIAL_SPECULAR,
//		U_MATERIAL_SHININESS,
//
//		U_LIGHT0_POSITION,
//		U_LIGHT0_COLOR,
//		U_LIGHT0_POWER,
//		U_LIGHT0_KC,
//		U_LIGHT0_KL,
//		U_LIGHT0_KQ,
//		U_LIGHT0_TYPE,
//		U_LIGHT0_SPOTDIRECTION,
//		U_LIGHT0_COSCUTOFF,
//		U_LIGHT0_COSINNER,
//		U_LIGHT0_EXPONENT,
//
//		U_LIGHT1_POSITION,
//		U_LIGHT1_COLOR,
//		U_LIGHT1_POWER,
//		U_LIGHT1_KC,
//		U_LIGHT1_KL,
//		U_LIGHT1_KQ,
//		U_LIGHT1_SPOTDIRECTION,
//		U_LIGHT1_TYPE,
//		U_LIGHT1_COSCUTOFF,
//		U_LIGHT1_COSINNER,
//		U_LIGHT1_EXPONENT,
//
//		U_LIGHTENABLED,
//		U_NUMLIGHTS,
//		U_COLOR_TEXTURE_ENABLED,
//		U_COLOR_TEXTURE,
//		U_TEXT_ENABLED,
//		U_TEXT_COLOR,
//
//		U_TOTAL,
//
//	};
//
//	enum NPCS {
//	
//		TECK_LEE = 0,
//		TECK_LING,
//		REYNARD,
//		TERRY,
//		DANIEL,
//		KEITH,
//		VICTOR,
//		BENNY,
//		HAO_MING,
//		SEK_HENG,
//
//		NUM_NPC,
//
//	};
//
//	//Constructors & Destructors
//	SpaceStation();
//	~SpaceStation();
//
//	virtual void Init();
//	virtual void Update(double dt);
//	virtual void Render();
//	virtual void Exit();
//
//private:
//
//	//Render Functions
//	void RenderMesh(Mesh *mesh, bool enableLight);
//	void RenderText(Mesh* mesh, std::string text, Colour colour);
//	void RenderTextWithDepth(Mesh* mesh, std::string text, Colour colour);
//	void RenderTextOnScreen(Mesh* mesh, std::string text, Colour colour, float size, float x, float y);
//	void RenderObjectOnScreen(Mesh* mesh, float size, float x, float y);
//	void RenderStartMenu();
//	void RenderInventory();
//	void RenderShip();
//	void RenderFPS();
//	void RenderObjects();
//	void RenderSkybox();
//	void RenderNPC();
//	void RenderQuests(string giver);
//	void RenderShop(string seller);
//
//	//Update Functions
//	void UpdateStartMenu();
//	void UpdateShop(string seller);
//	void UpdateQuests(string giver);
//
//	//Bounds Checking
//	void boundsChecking(Vector3* position);
//	void npcInteraction();
//
//	//Other Functions
//	void CheckKeyPress();
//
//	//Animation
//	void PlayLeavingAnimation(double &dt);
//
//	//Variables
//	unsigned int m_programID;
//	unsigned int m_parameters[U_TOTAL];
//	unsigned int m_vertexArrayID;
//	
//	int ScreenMidX, ScreenMidY;
//
//	double frameRate;
//	
//	bool isPressed[NUM_KEY];
//
//	CameraFPS camera;
//	
//	Mesh *meshList[NUM_GEOMETRY];
//	
//	MS modelStack, viewStack, projectionStack;
//	
//	PLAYER_STATE playerState;
//	MENU_OPTION menuOption;
//
//	Light light[2];
//	
//	NPC npcs[NUM_NPC];
//	string shopKeeperName;
//	string questGiverName;
//
//	vector<CollideObj> objs;
//	bool pause;
//
//};
//
//#endif
#include "GameScene.h"

//Constructor
GameScene::GameScene() {

	mesh[FONT_CONSOLAS] = MeshBuilder::GenerateText("Text", 16, 16);
	mesh[FONT_CONSOLAS]->textureID = LoadTGA("Image//Fonts//Consolas.tga");

	for (GEOMETRY_TYPE i = SKYBOX_TOP; i <= SKYBOX_RIGHT; i = static_cast<GEOMETRY_TYPE>(i + 1)) {
	
		mesh[i] = MeshBuilder::GenerateQuad("Skybox", Colour(1, 1, 1), 1.0f);
		mesh[i]->textureID = LoadTGA("Image//PlaceHolder//PlaceHolder.tga");

	}

}

//Destructor
GameScene::~GameScene() {
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

void GameScene::RenderObjectOnScreen(Mesh* mesh, float sizex,float sizey,float sizez, float x, float y,float rotate,float rx,float ry,float rz) {

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
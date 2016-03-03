#include "PlayerControl.h"

extern GLFWwindow* m_window;

/******************************************************************************/
/*!

\brief
An empty constructor.

*/
/******************************************************************************/
PlayerControl::PlayerControl() {
}

/******************************************************************************/
/*!

\brief
An empty destructor.

*/
/******************************************************************************/
PlayerControl::~PlayerControl() {
}

/******************************************************************************/
/*!

\brief
Rotates the player's ship.

\param ship
The player's ship.

\param maxTurningAngle
The maximum angle the ship can rotate this frame.

\param dt
The time taken for this frame to complete.

*/
/******************************************************************************/
void PlayerControl::RotateShip(Ship* ship, float maxTurningAngle, double &dt) {

	float centreMouseSpeed = 0.95f;//The bigger the faster. 1 is that max and 0 is the min
	int screenSizeX, screenSizeY;
	double screenMidX, screenMidY;
	
	glfwGetWindowSize(m_window, &screenSizeX, &screenSizeY);

	screenMidX = screenSizeX/2;
	screenMidY = screenSizeY/2;

	//GLFW Method
	MousePosition mousePosition;
	glfwGetCursorPos(m_window, &mousePosition.x, &mousePosition.y);
	glfwSetCursorPos(m_window, (1 - (dt * centreMouseSpeed))*(mousePosition.x - screenMidX) + screenMidX, (1 - (dt * centreMouseSpeed))*(mousePosition.y - screenMidY) + screenMidY);

	if (mousePosition.x > screenSizeX * 0.9) {
		mousePosition.x = screenSizeX * 0.9;
		glfwSetCursorPos(m_window, screenSizeX * 0.9, mousePosition.y);
	} else if (mousePosition.x < screenSizeX/10) {
		mousePosition.x = 0;
		glfwSetCursorPos(m_window, screenSizeX * 0.1, mousePosition.y);
	} if (mousePosition.y > screenSizeY * 0.9) {
		mousePosition.y = screenSizeY;
		glfwSetCursorPos(m_window, mousePosition.x, screenSizeY * 0.9);
	} else if (mousePosition.y < screenSizeY/10) {
		mousePosition.y = 0;
		glfwSetCursorPos(m_window, mousePosition.x, screenSizeY * 0.1);
	}

	Vector3 rotation(0, 0, 0);

	rotation.y -= (float)(mousePosition.x - screenMidX)/150.0f;

	if (rotation.y > maxTurningAngle) {
		rotation.y = maxTurningAngle;
	} else if (rotation.y < -maxTurningAngle) {
		rotation.y = -maxTurningAngle;
	}
	
	rotation.x += (float)(mousePosition.y - screenMidY)/150.0f;

	if (rotation.x > maxTurningAngle) {
		rotation.x = maxTurningAngle;
	} else if (rotation.x < -maxTurningAngle) {
		rotation.x = -maxTurningAngle;
	}

	if (Application::IsKeyPressed('A')) {
		rotation.z -= (float)(90.0f * dt);
	}

	if (Application::IsKeyPressed('D')) {
		rotation.z += (float)(90.0f * dt);
	}

	ship->Rotate(0, 0, rotation.z);
	ship->Rotate(rotation.x, 0, 0);
	ship->Rotate(0, rotation.y, 0);

}

/******************************************************************************/
/*!

\brief
Moves the player's ship by applying a force in the ship's forward direction.

\param ship
The player's ship.

\param force
The magnitude of the force to apply on the ship.

\dt
The time taken for this frame to complete.

*/
/******************************************************************************/
void PlayerControl::MoveShip(PlayerShip* ship, float force, double &dt) {

	if (Application::IsKeyPressed('W')) {

		ship->IncreaseSpeed(dt * 10.0f);

	}

	if (Application::IsKeyPressed('S')) {
	
		ship->DecreaseSpeed(dt * 20.0f);

	}
	
	ship->AddRelativeForce(0.0f, 0.0f, force, dt);

	if (ship->GetVelocity().Length() > ship->GetSpeed()) {
	
		if (ship->GetVelocity().Length() <= 0.1f) {
		
			ship->SetVelocity(0.0f, 0.0f, 0.0f);
			ship->SetAcceleration(0.0f, 0.0f, 0.0f);

		} else {

			ship->SetVelocity(ship->GetVelocity().Normalized() * ship->GetSpeed());
			ship->SetAcceleration(0.0f, 0.0f, 0.0f);

		}

	}

}

/******************************************************************************/
/*!

\brief
Makes the player's ship shoot upon pressing the left mouse button.

\param ship
The player's ship.

\param bulletPosition
The spawn position of the bullet.

*/
/******************************************************************************/
void PlayerControl::Shoot(Ship* ship, Vector3 bulletPosition) {

	if (Application::IsKeyPressed(VK_LBUTTON)) {
	
		ship->Shoot(bulletPosition);

	}

}
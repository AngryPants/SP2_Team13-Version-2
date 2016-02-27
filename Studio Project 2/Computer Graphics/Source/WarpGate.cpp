#include "WarpGate.h"

WarpGate::WarpGate(Vector3 exitPosition, float messageRadius, float interactRadius, string message, string name, string meshFile, const char* textureFile, Material material)
: Interactable(messageRadius, interactRadius, message, name, meshFile, textureFile, material)
{
	this->exitPosition = exitPosition;
}

WarpGate::~WarpGate()
{

}

void WarpGate::Interact(RigidBody* object, double &dt)
{
	if (Physics::getDistance(object->GetPosition(), this->GetPosition())<GetMessageRadius() && Physics::getDistance(object->GetPosition(), this->GetPosition())>GetInteractRadius())
	{
		SetRenderMessage("A portal is Nearby");
	}
	else if (Physics::getDistance(object->GetPosition(), this->GetPosition())<GetInteractRadius())
	{
		SetRenderMessage("Press E to Teleport");
		if (Application::IsKeyPressed('E'))
		{
			SetInteracting(true);
		}
	}
	else //if not close to portal
	{
		SetRenderMessage("");
	}
}

void WarpGate::PlayAnimation(RigidBody* object, double &dt)
{
	if (GetInteracting() == true)
	{
		//object->SetVelocity(0);
		//Vector3 current, end;
		//playAnimation
		//int endpos = Physics::getDistance(object->GetForwardVector()*dt*100.0f, this->GetForwardVector());
		//object->SetPosition(this->position + this->GetForwardVector());
		//object->SetPosition(this->position /*- this->GetForwardVector().y*/);
		//std::cout << GetForwardVector() << std::endl;
		/*current.Set(object->GetPosition().x, object->GetPosition().y, object->GetPosition().z);
		end.Set(object->GetPosition().x + GetForwardVector().x, object->GetPosition().y + GetForwardVector().y, object->GetPosition().z + GetForwardVector().z);
		while (current.z != end.z )
		{*/
		//object->AddVelocity(0, 0, 100000);
		//object->SetVelocity(object->GetVelocity() + Vector3(10, 10, 10)); //AddForce(0,0,10000,dt);
		//}
		
		object->SetPosition(exitPosition);
		SetInteracting(false);

		/*int startpos = Physics::getDistance(object->GetPosition(), this->GetForwardVector()+(2*GetForwardVector()) );
		while (startpos < endpos )
		{
			object->AddRelativeForce(0,1,0,dt);
		}*/
		/*if (Physics::getDistance(object->GetPosition(), this->GetPosition()) > GetInteractRadius())
		{*/
		//}
	}
}






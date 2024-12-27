#include <iostream> 

#include "Entity.h"
#include "Player.h"

int main()
{
	/*Entity* entity = new Entity();
	std::cout << entity->GetName() << '\n';*/

	//Player* player = new Player("RonnieJ");
	IEntity* player = new Player("RonnieJ"); // Upcasting
	std::cout << player->GetName() << '\n';

	//delete entity;
	delete player;
}
#include "Event.hpp"

Event::Event()
{
	srand(time(NULL));
	int dice_roll = rand() % 4 + 1;

	switch (dice_roll)
	{
	case 1:	// Nothing
		enemy = nullptr;
		loot = 0;
		break;
	case 2:	// Enemy 1
		dice_roll = rand() % 4 + 1;
		enemy = new Enemy(65, 6, 40, 4, (7 * dice_roll));
		loot = 50;
		break;
	case 3: // Enemy 2
		dice_roll = rand() % 4 + 1;
		enemy = new Enemy(90, 3, 32, 6, (7 * dice_roll));
		loot = 180;
		break;
	case 4:	// Loot
		enemy = nullptr;
		loot = 100;
		break;
	}
}
Event::~Event()
{
	if (enemy != nullptr)
		delete enemy;
}

bool Event::isEnemy() const
{
	if (enemy != nullptr)
		return true;
	else
		return false;
}
Enemy* Event::getEnemy() const
{
	return enemy;
}
int Event::getLoot() const
{
	return loot;
}
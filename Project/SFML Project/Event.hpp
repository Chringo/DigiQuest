#ifndef EVENT_HPP
#define EVENT_HPP

#include <random>
#include "Enemy.hpp"

class Event
{
public:
	Event();
	~Event();

	bool isEnemy() const;
	Enemy* getEnemy() const;
	int getLoot() const;
private:
	unsigned int loot;
	Enemy* enemy;
};
#endif
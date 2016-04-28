#ifndef UNIT_HPP
#define UNIT_HPP

class Unit
{
public:
	Unit();
	virtual ~Unit();

	virtual int throwDie();
	virtual int throwDie(int sides) = 0;
private:
	int health;
	int stamina;
	int recovery;
	int energy;
	unsigned int loot;
};
#endif
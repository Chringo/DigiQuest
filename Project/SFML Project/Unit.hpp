#ifndef UNIT_HPP
#define UNIT_HPP
#include <SFML\Graphics.hpp>
#include <random>

class Unit : public sf::Drawable
{
public:
	Unit();
	virtual ~Unit();

	virtual void Update(float dt) = 0;
	//virtual int throwDie();
	//virtual int throwDie(int sides) = 0;
	int getLoot() const;
protected:
	int health;		// Character's health
	int recovery;	// Affects health each turn
	int stamina;	// Character's points to do actions
	int energy;		// Affects stamina each turn
	unsigned int loot;

	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	sf::RectangleShape* mStats;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};
#endif
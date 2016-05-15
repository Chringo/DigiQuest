#include "Unit.hpp"

Unit::Unit()
{
	health = -1;
	stamina = -1;
	recovery = -1;
	energy = -1;
	loot = 0;

	sf::String fileName = "../Resources/bgd_unit.png";
	if (!mBackgroundTex.loadFromFile(fileName))
	{
		// Handle error
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
	mBackgroundSprite.setTextureRect(sf::IntRect(0, 0, 300, 380));

	mStats = nullptr;
}
Unit::~Unit(){}

int Unit::getLoot() const
{
	return loot;
}
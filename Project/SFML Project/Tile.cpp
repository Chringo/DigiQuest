#include "Tile.hpp"

Tile::Tile()
{
	land = Plain;
	cost = -1;
	pos = sf::Vector2f();
	passable = false;
}
Tile::Tile(eType _land, int _cost, sf::Vector2f _pos)
{
	land = _land;
	cost = _cost;
	pos = _pos;
	if (land == Water)
		passable = false;
	else
		passable = true;

	sf::String fileName;
	switch (land)
	{
	case Plain:
		fileName = "../Resources/plain.png";
		break;
	case Start:
		fileName = "../Resources/start.png";
		break;
	case Goal:
		fileName = "../Resources/goal.png";
		break;
	default:
		fileName = "../Resources/goal.png";
		break;
	}
	if (!mTexture.loadFromFile(fileName))
	{
		// Handle error
	}
	mSpriteSheet.setPosition(pos);
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 140, 120));
}
Tile::~Tile(){}

sf::Vector2f Tile::getPos() const
{
	return pos;
}
void Tile::setMoveCost(int _cost)
{
	cost = _cost;
}
int Tile::getMoveCost() const
{
	return land;
}
bool Tile::isPassable() const
{
	return passable;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}
#include "Tile.hpp"

Tile::Tile()
{
	land = Plain;
	cost = -1;
	passable = false;

	pos = sf::Vector2f();
}
Tile::Tile(eType _land, sf::Vector2f _pos)
{
	land = _land;
	cost = 1;
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
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 140, 120));
	mSpriteSheet.setPosition(pos);
}
Tile::~Tile(){}

//int Tile::getCol() const
//{
//	return col;
//}
//int Tile::getRow() const
//{
//	return row;
//}
int Tile::getMoveCost() const
{
	return cost;
}
bool Tile::isPassable() const
{
	return passable;
}
sf::Vector2f Tile::getPos() const
{
	return pos;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}
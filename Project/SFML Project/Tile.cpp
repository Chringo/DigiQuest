#include "Tile.hpp"

Tile::Tile()
{
	col = -1;
	row = -1;
	land = Plain;
	cost = -1;
	passable = false;

	pos = sf::Vector2f();
}
Tile::Tile(int _col, int _row, eType _land, int _cost, sf::Vector2f _pos)
{
	col = _col;
	row = _row;
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

int Tile::getCol() const
{
	return col;
}
int Tile::getRow() const
{
	return row;
}
void Tile::setMoveCost(int _cost)
{
	cost = _cost;
}
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
#include "Tile.hpp"

Tile::Tile()
{
	land = Plain;
	cost = -1;
	passable = false;

	gPos = sf::Vector2f();
}
Tile::Tile(eType _land, const sf::Texture* _tex, sf::Vector2f _pos)
{
	land = _land;
	cost = 1;
	gPos = _pos;
	if (land == Water)
		passable = false;
	else
		passable = true;

	mSpriteSheet.setTexture(*_tex);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 140, 120));
	mSpriteSheet.setPosition(gPos);
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
sf::Vector2f Tile::getScreenPos() const
{
	return gPos;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}
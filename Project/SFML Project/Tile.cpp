#include "Tile.hpp"

Tile::Tile()
{
	m_Land = Goal;
	m_Cost = -1;
	m_Passable = false;
}

Tile::Tile(eType land, const sf::Texture* tex, sf::Vector2f pos)
{
	m_Land = land;
	if (m_Land == Plain || m_Land == Start || m_Land == Goal)
	{
		m_Cost = 1;
		m_Passable = true;
	}
	else if (m_Land == Hill)
	{
		m_Cost = 3;
		m_Passable = true;
	}
	else if (m_Land == Forest)
	{
		m_Cost = 2;
		m_Passable = true;
	}
	else if (m_Land == Water)
	{
		m_Cost = 0;
		m_Passable = false;
	}

	m_SpriteSheet.setTexture(*tex);
	m_SpriteSheet.setTextureRect(sf::IntRect(0, 0, 140, 120));
	m_SpriteSheet.setPosition(pos);
}
Tile::~Tile(){}

int Tile::getMoveCost() const
{
	return m_Cost;
}
bool Tile::isPassable() const
{
	return m_Passable;
}
sf::Vector2f Tile::getScreenPos() const
{
	return m_SpriteSheet.getPosition();
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_SpriteSheet, states);
}
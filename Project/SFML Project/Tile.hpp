#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>

class Tile : public sf::Drawable
{
public:
	static enum eType : unsigned int
	{
		Plain = 0,
		Hill,
		Forest,
		Water,
		Start,
		Goal
	};
	static const int TILETYPECOUNT = 6;

	Tile();
	Tile(eType land, const sf::Texture* texture, sf::Vector2f position);
	~Tile();

	int getMoveCost() const;
	bool isPassable() const;

	sf::Vector2f getScreenPos() const;
private:
	eType m_Land;
	short int m_Cost;
	bool m_Passable;
	
	sf::Texture m_Texture;
	sf::Sprite m_SpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
#ifndef TILE_HPP
#define TILE_HPP

#include <SFML\Graphics.hpp>

class Tile : public sf::Drawable
{
public:
	enum eType : unsigned int
	{
		Plain = 0,
		Hill,
		Forest,
		Water,
		Start,
		Goal
	};

	Tile();
	Tile(eType land, int cost, sf::Vector2f pos);
	virtual ~Tile();

	//void setPos(sf::Vector2f pos);
	sf::Vector2f getPos() const;
	void setMoveCost(int cost);
	int getMoveCost() const;
	bool isPassable() const;

	//void Update(float dt);
private:
	eType land;
	sf::Vector2f pos;
	short int cost;
	bool passable;
	
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
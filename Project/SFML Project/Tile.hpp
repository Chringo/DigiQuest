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
	Tile(int column, int row, eType land, int cost, sf::Vector2f position);
	virtual ~Tile();

	int getCol() const;
	int getRow() const;
	void setMoveCost(int cost);
	int getMoveCost() const;
	bool isPassable() const;

	sf::Vector2f getPos() const;
	//void Update(float dt);
private:
	short int col;
	short int row;
	eType land;
	short int cost;
	bool passable;

	sf::Vector2f pos; // Graphical purpose
	
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
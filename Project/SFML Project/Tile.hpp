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
	virtual ~Tile();

	//int getCol() const;
	//int getRow() const;
	int getMoveCost() const;
	bool isPassable() const;

	sf::Vector2f getScreenPos() const;
	//void Update(float dt); // For animation
private:
	//short int col;
	//short int row;
	eType land;
	short int cost;
	bool passable;

	sf::Vector2f gPos; // Graphical purpose
	
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
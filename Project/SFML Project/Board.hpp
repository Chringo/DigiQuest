#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Tile.hpp"

//const int BOARDWIDTH = 5;
//const int BOARDHEIGHT = 5;
class Board : public sf::Drawable
{
public:
	Board();
	virtual ~Board();
	void loadBoard();

	bool setActiveTile(int x, int y);
	sf::Vector2f getActiveTilePos() const;
	sf::Vector2f* getAdjoinedTiles();
	void Update(float dt);

	void printTileCost();
private:
	static const int WIDTH = 5;		// Number of columns
	static const int HEIGHT = 5;	// Number of rows
	Tile* tiles[WIDTH][HEIGHT];
	Tile* active;
	sf::Vector2f* adjoined;

	// Textureholder
	sf::Texture mTileTextures[Tile::TILETYPECOUNT];
	void loadTileTextures();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Tile.hpp"

class Board : public sf::Drawable
{
public:
	Board();
	virtual ~Board();

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

	// Hold one of each tile type
	Tile startTile;
	Tile goalTile;
	Tile plainTile;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
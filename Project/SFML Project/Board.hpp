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
	Tile*** tiles;
	int width;
	int height;
	Tile* active;
	sf::Vector2f* adjoined;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
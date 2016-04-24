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

	void Update(float dt);

	void print();
private:
	Tile*** tiles;
	int boardWidth;
	int boardHeight;



	//sf::Texture mTexture;
	//sf::Sprite mSpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
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

	sf::Vector2f getPlayerPos() const;
	void Update(float dt);

	void print();
private:
	Tile*** tiles;
	int boardWidth;
	int boardHeight;
	sf::Vector2f playerPos;



	//sf::Texture mTexture;
	//sf::Sprite mSpriteSheet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPlayerPos(sf::Vector2f pos);
};
#endif
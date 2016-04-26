#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Board.hpp"
#include "Player.hpp"

class Game : public sf::Drawable
{
public:
	Game();
	virtual ~Game();

	void Update(float dt);

private:
	bool was_A;
	bool was_S;
	bool was_D;
	bool playerWalking;

	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;

	Board* board;
	Player* player;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include <queue>
#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Event.hpp"

class Game : public sf::Drawable
{
public:
	Game();
	virtual ~Game();

	void Update(sf::Event* _event, float deltatime);

private:
	enum State : unsigned int
	{
		START = 0,
		GAME,
		GOAL,
		GAMEOVER
	};
	int currentstate;

	bool was_A;
	bool was_S;
	bool was_D;
	bool playerWalking;
	int playerX;
	int playerY;

	Board* board;
	Player* player;
	std::queue<Event*> qEvents;
	Enemy* aEnemy;

	bool combat(Player* player, Enemy* aEnemy);

	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	sf::Texture mInfosTex;
	sf::Sprite mInfoSprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif
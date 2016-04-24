#include "Game.hpp"

Game::Game()
{
	if (!mBackgroundTex.loadFromFile("../Resources/bgd_wood.png"))
	{
		// Handle error
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
	
	board = new Board();
	//player = new Player(1);
}
Game::~Game()
{
	delete board;
	//delete player;
}

void Game::Update(float dt)
{
	// Make sure everything in the game is updated (if needed).
	board->Update(dt);
	//player->Update(dt);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(mBackgroundSprite, states);
	target.draw(*board, states);
	//target.draw(*player, states);
}
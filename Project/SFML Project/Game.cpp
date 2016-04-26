#include "Game.hpp"

Game::Game()
{
	if (!mBackgroundTex.loadFromFile("../Resources/bgd_wood.png"))
	{
		// Handle error
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
	
	board = new Board();
	player = new Player(board->getPlayerPos());
}
Game::~Game()
{
	delete board;
	delete player;
}

void Game::Update(float dt)
{
	int key;
	bool is_A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	if (is_A && !was_A && !playerWalking)
	{
		
	}


	board->Update(dt);
	player->Update(dt, board->getPlayerPos());
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(mBackgroundSprite, states);
	target.draw(*board, states);
	target.draw(*player, states);
}
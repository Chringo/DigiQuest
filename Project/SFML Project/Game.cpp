#include "Game.hpp"

Game::Game()
{
	// Background
	if (!mBackgroundTex.loadFromFile("../Resources/bgd_wood.png"))
	{
		// Handle error
	}
	mBackgroundSprite.setTexture(mBackgroundTex);

	currentstate = State::START;
	board = new Board();
	player = nullptr;
	was_A = false;
	was_S = false;
	was_D = false;
	//player = new Player(board->getActiveTilePos());
	for (int i = 0; i < 9; i++)
		qEvents.push(new Event());
	//if (qEvents.front()->isEnemy())
	//	aEnemy = qEvents.front()->getEnemy();
	//else
	aEnemy = nullptr;
}
Game::~Game()
{
	delete board;
	delete player;
	for (int i = qEvents.size(); i > 0; i--)
	{
		delete qEvents.front();
		qEvents.pop();
	}
}

void Game::Update(sf::Event* e, float dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		if (player == nullptr)
		{
			playerX = 1;
			playerY = 0;
			board->setActiveTile(playerX, playerY);
			player = new Player(board->getActiveTilePos());
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
	{
		if (player == nullptr)
		{
			playerX = 3;
			playerY = 0;
			board->setActiveTile(playerX, playerY);
			player = new Player(board->getActiveTilePos());
		}
	}

	bool is_S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool is_A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool is_D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (is_S && !was_S)
	{
		if (board->setActiveTile(playerX, playerY + 1))
		{
			playerY++;
			was_S = true;
		}
	}

	if (was_S)
	{
		// Start event
		if (qEvents.front()->isEnemy())
		{
			aEnemy = qEvents.front()->getEnemy();
			if (combat(player, aEnemy))
				player->addLoot(qEvents.front()->getLoot());
		}
		else
		{
			aEnemy = nullptr;
		}

		// Clear event
		//delete qEvents.front();
		//qEvents.pop();

		//printf("%d", player->getLoot());
	}


	board->Update(dt);
	if (player != nullptr)
	{
		player->Update(dt, board->getAdjoinedTiles());
	}
	if (aEnemy != nullptr)
	{
		aEnemy->Update(dt);
	}
	was_S = is_S;
}
bool Game::combat(Player* player, Enemy* aEnemy)
{
	return false;
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mBackgroundSprite, states);
	target.draw(*board, states);
	if (player != nullptr)
		target.draw(*player, states);
	if (aEnemy != nullptr)
		target.draw(*aEnemy, states);
}
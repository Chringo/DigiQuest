#include "Board.hpp"

Board::Board()
{
	float strt = 900;
	boardWidth = 3;
	boardHeight = 5;

	// Initiate Tiles
	tiles = new Tile**[boardWidth];
	for (int i = 0; i < boardWidth; i++)
	{
		tiles[i] = new Tile*[boardHeight];
	}

	// Set Tiles and hexagon pattern
	for (int x = 0; x < boardWidth; x++)
	{
		for (int y = 0; y < boardHeight; y++)
		{
			if (x & 1)
			{
				if (y == 0)
					tiles[x][y] = new Tile(Tile::Start, 3, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else if (y == (boardHeight - 1))
					tiles[x][y] = new Tile(Tile::Goal, 3, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else
					tiles[x][y] = new Tile(Tile::Plain, 3, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
			}
			else
			{
				if (y == 0)
					tiles[x][y] = nullptr;
				else
					tiles[x][y] = new Tile(Tile::Forest, 3, sf::Vector2f((strt + 106.f * x), (30.f + 121.f * y)));
			}
		}
	}
}
Board::~Board()
{
	for (int x = 0; x < boardWidth; x++)
	{
		for (int y = 0; y < boardHeight; y++)
		{
			delete tiles[x][y];
		}
		delete[] tiles[x];
	}
	delete tiles;
}

void Board::Update(float dt)
{
	//error LNK2005: "public: virtual void * __thiscall Tile::`vector deleting destructor'(unsigned int)" (??_ETile@@UAEPAXI@Z) already defined in Tile.obj	*\Board.obj
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//target.draw(mSpriteSheet, states);

	for (int x = 0; x < boardWidth; x++)
	{
		for (int y = 0; y < boardHeight; y++)
		{
			if (tiles[x][y] != nullptr)
				target.draw(*tiles[x][y], states);
		}
	}
}

void Board::print()
{
	for (int i = 0; i < boardHeight; i++)
	{
		//printf("%d ", tiles[i].getMoveCost());
	}
}

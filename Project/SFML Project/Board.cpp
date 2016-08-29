#include "Board.hpp"

Board::Board()
{
	float strt = 680;

	// Set hexagon pattern
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (x & 1) // Odd column
			{
				if (y == 0)
					tiles[x][y] = new Tile(Tile::Start, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else if (y == (HEIGHT - 1))
					tiles[x][y] = new Tile(Tile::Goal, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else
					tiles[x][y] = new Tile(Tile::Plain, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
			}
			else // Even column
			{
				if (y == 0)
					tiles[x][y] = nullptr;
				else
					tiles[x][y] = new Tile(Tile::Plain, sf::Vector2f((strt + 106.f * x), (30.f + 121.f * y)));
			}
		}
	}
	// Set Player Start Position - Will be a choice later on
	active = tiles[1][0];

	adjoined = new sf::Vector2f[3];

	this->printTileCost();
}
Board::~Board()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			delete tiles[x][y];
		}
	}

	delete[] adjoined;
}

bool Board::setActiveTile(int x, int y)
{
	if (x < 0 || x >= WIDTH)
	{
		return false;
	}
	else if (y >= HEIGHT)
	{
		return false;
	}
	else
	{
		active = tiles[x][y];
		return true;
	}
}
sf::Vector2f Board::getActiveTilePos() const
{
	//return active->getPos();
	return sf::Vector2f();
}
sf::Vector2f* Board::getAdjoinedTiles()
{
	//int activeCol = active->getCol();
	//int activeRow = active->getRow();
	//if (active->getCol() & 1)
	//{
	//	adjoined[0] = tiles[activeCol - 1][activeRow + 1]->getPos();
	//	adjoined[1] = tiles[activeCol + 0][activeRow + 1]->getPos();
	//	adjoined[2] = tiles[activeCol + 1][activeRow + 1]->getPos();
	//}
	//printf("%.f, %.f \n", adjoined[0].x, adjoined[0].y);
	//printf("%.f, %.f \n", adjoined[1].x, adjoined[1].y);
	//printf("%.f, %.f \n", adjoined[2].x, adjoined[2].y);
	return adjoined;
}
void Board::Update(float dt)
{
	
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Draw board of tiles
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (tiles[x][y] != nullptr)
				target.draw(*tiles[x][y], states);
		}
	}
}

void Board::printTileCost()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (tiles[x][y] != nullptr)
				printf("%d ", tiles[x][y]->getMoveCost());
			else
				printf("  ");
		}
		printf("\n");
	}
}

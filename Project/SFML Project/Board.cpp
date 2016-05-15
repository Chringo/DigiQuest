#include "Board.hpp"

Board::Board()
{
	float strt = 680;
	width = 5;	// Number of columns
	height = 5;	// Number of rows

	// Initiate Tiles
	tiles = new Tile**[width];
	for (int i = 0; i < width; i++)
	{
		tiles[i] = new Tile*[height];
	}
	// Initiate array for adjoined tile positions
	adjoined = new sf::Vector2f[3];

	// Set Tiles and hexagon pattern
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x & 1) // Odd column
			{
				if (y == 0)
					tiles[x][y] = new Tile( x, y, Tile::Start, 1, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else if (y == (height - 1))
					tiles[x][y] = new Tile( x, y, Tile::Goal, 1, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
				else
					tiles[x][y] = new Tile( x, y, Tile::Plain, 1, sf::Vector2f((strt + 106.f * x), (90.f + 121.f * y)));
			}
			else // Even column
			{
				if (y == 0)
					tiles[x][y] = nullptr;
				else
					tiles[x][y] = new Tile( x, y, Tile::Plain, 1, sf::Vector2f((strt + 106.f * x), (30.f + 121.f * y)));
			}
		}
	}
	// Set Player Start Position - Will be a choice later on
	active = tiles[1][0];

	this->printTileCost();
}
Board::~Board()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			delete tiles[x][y];
		}
		delete[] tiles[x];
	}
	delete tiles;

	delete[] adjoined;
}

bool Board::setActiveTile(int x, int y)
{
	if (x < 0 || x >= width)
	{
		return false;
	}
	else if (y >= height)
	{
		return false;
	}
	else
	{
		active = tiles[x][y];
	}
}
sf::Vector2f Board::getActiveTilePos() const
{
	return active->getPos();
}
sf::Vector2f* Board::getAdjoinedTiles()
{
	int activeCol = active->getCol();
	int activeRow = active->getRow();
	if (active->getCol() & 1)
	{
		adjoined[0] = tiles[activeCol - 1][activeRow + 1]->getPos();
		adjoined[1] = tiles[activeCol + 0][activeRow + 1]->getPos();
		adjoined[2] = tiles[activeCol + 1][activeRow + 1]->getPos();
	}
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
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (tiles[x][y] != nullptr)
				target.draw(*tiles[x][y], states);
		}
	}
}

void Board::printTileCost()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (tiles[x][y] != nullptr)
				printf("%d ", tiles[x][y]->getMoveCost());
			else
				printf("  ");
		}
		printf("\n");
	}
}

#include "Board.hpp"

Board::Board()
{
	// "Initiate" Tiles
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			tiles[x][y] = nullptr;
		}
	}
	adjoined = nullptr;
	//active = nullptr;

	// Import Tile textures
	this->importTileTextures();

	this->loadBoard();
	//this->printTileCost();
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

	if (adjoined != nullptr)
		delete[] adjoined;

}
void Board::loadBoard()
{
	const float screenPos = 680;

	// Define board and set the hexagon pattern
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (x & 1) // Odd column
			{
				if (y == 0)
					tiles[x][y] = new Tile(Tile::Start, &mTileTextures[Tile::Start], sf::Vector2f((screenPos + 106.f * x), (90.f + 121.f * y)));
				else if (y == (HEIGHT - 1))
					tiles[x][y] = new Tile(Tile::Goal, &mTileTextures[Tile::Goal], sf::Vector2f((screenPos + 106.f * x), (90.f + 121.f * y)));
				else
					tiles[x][y] = new Tile(Tile::Water, &mTileTextures[Tile::Water], sf::Vector2f((screenPos + 106.f * x), (90.f + 121.f * y)));
			}
			else // Even column
			{
				if (y == 0)
					tiles[x][y] = nullptr;
				else
					tiles[x][y] = new Tile(Tile::Plain, &mTileTextures[Tile::Plain], sf::Vector2f((screenPos + 106.f * x), (30.f + 121.f * y)));
			}
		}
	}

	//// Set Player Start Position
	//active = tiles[1][0];

	//adjoined = new sf::Vector2f[3];
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

void Board::loadTileTexture(unsigned int tile, const sf::String &file)
{
	if (!mTileTextures[tile].loadFromFile(file))
	{
		// Handle error
		mTileTextures[tile].create(140, 120);
	}
}
void Board::importTileTextures()
{
	sf::String fileName;
	fileName = "../Resources/plain.png";
	this->loadTileTexture(Tile::Plain, fileName);
	fileName = "../Resources/hill.png";
	this->loadTileTexture(Tile::Hill, fileName);
	fileName = "../Resources/forest.png";
	this->loadTileTexture(Tile::Forest, fileName);
	fileName = "../Resources/water.png";
	this->loadTileTexture(Tile::Water, fileName);
	fileName = "../Resources/start.png";
	this->loadTileTexture(Tile::Start, fileName);
	fileName = "../Resources/goal.png";
	this->loadTileTexture(Tile::Goal, fileName);
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

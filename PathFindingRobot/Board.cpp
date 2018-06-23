#include "Board.h"
using namespace std;


Board::Board()
{
	Map = nullptr;
	Start = End = nullptr;
	Height = Width = Wall = 0;
}

Board::Board(const Board & B)
{
	this->operator=(B);
}

Board::Board(int height, int width, int wall, int distance)
{
	Height = height;
	Width = width;
	Map = new Tile*[Width];
	for (int i = 0; i < Width; i++)
		Map[i] = new Tile[Height];

	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
		{
			Map[j][i].x = j;
			Map[j][i].y = i;
			Map[j][i].Type = ' ';
			Map[j][i].Checked = false;
		}
	Wall = wall;

	int maxdistance = Width - 1 + Height - 1;
	if (distance > maxdistance)
		distance = maxdistance;

	Distance = distance;

	Generate();
}

void Board::Generate()
{
	if (Height == 0 || Width == 0)
		return;

	srand((unsigned int)time(nullptr));
	if (Wall >= Height * Width)
		Wall = Height * Width - 2;


	/*Map[Width - 1][0].Type = 'S';
	Map[0][Height - 1].Type = 'G';
	Start = &Map[Width - 1][0];
	End = &Map[0][Height - 1];*/

	int i = rand() % Height, j = rand() % Width,
		k = rand() % Height, l = rand() % Width;

	for (;
		(Distance == 0 && i - k + j - l == 0) || (Distance > 0 && i - k + j - l < Distance);
		i = rand() % Height, j = rand() % Width,
		k = rand() % Height, l = rand() % Width);

	if (rand() % 2 == 1)
		swap<int>(j, l);

	Map[j][i].Type = 'S';
	Start = &Map[j][i];

	Map[l][k].Type = 'G';
	End = &Map[l][k];

	/*while (true)
	{
		int i = rand() % Height, j = rand() % Width;

		if (Map[j][i].Type != ' ')
			continue;

		Map[j][i].Type = 'S';
		Start = &Map[j][i];
		break;
	}

	while (true)
	{
		int i = rand() % Height, j = rand() % Width;

		if (Map[j][i].Type != ' ')
			continue;

		Map[j][i].Type = 'G';
		End = &Map[j][i];
		break;
	}*/


	for (int z = Wall; z > 0;)
	{
		int i = rand() % Height, j = rand() % Width;

		if (Map[j][i].Type != ' ')
			continue;

		Map[j][i].Type = (char)254u;
		z--;
	}	
	
}

void Board::Display() const
{
	if (Height == 0 || Width == 0)
		return;

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			cout << " ";
			cout << Map[j][i].Type;
			//cout << " ";
		}
		cout << endl;
	}
}

Tile ** Board::getMap() const
{
	return Map;
}

Tile * Board::getStart() const
{
	return Start;
}

Tile * Board::getEnd() const
{
	return End;
}

int Board::getHeight() const
{
	return Height;
}

int Board::getWidth() const
{
	return Width;
}

void Board::Clear()
{
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
		{
			Map[j][i].Type = ' ';
			Map[j][i].Checked = false;
		}
}

Board & Board::operator=(const Board & B)
{
	if (Height != B.Height || Width != B.Width)
	{
		Height = B.Height;
		Width = B.Width;
		Map = new Tile*[Width];
		for (int i = 0; i < Width; i++)
			Map[i] = new Tile[Height];
	}

	Wall = B.Wall;
	Distance = B.Distance;

	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
		{
			Map[j][i].x = j;
			Map[j][i].y = i;
			Map[j][i].Type = B.Map[j][i].Type;
			Map[j][i].Checked = false;
		}

	Start = &Map[B.getStart()->x][B.getStart()->y];
	End = &Map[B.getEnd()->x][B.getEnd()->y];

	return *this;
}

Board::~Board()
{
	for (int i = 0; i < Height; i++)
		delete[] Map[i];
	delete[] Map;

	if (Start) Start = nullptr;
	if (End) End = nullptr;
}

std::ostream & operator<<(std::ostream & out, const Board & B)
{
	B.Display();
	return out;
}

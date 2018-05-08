#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

struct Tile
{
	char Type;
	bool Checked;
	int x, y;
};

class Board
{
private:
	Tile **Map;	
	int Height, Width, Wall, Distance;
	Tile *Start, *End;
public:
	Board();
	Board(const Board& B);
	Board(int height, int width, int wall, int distance);
	void Generate();
	void Display() const;

	Tile **getMap() const;
	Tile *getStart() const;
	Tile *getEnd() const;
	int getHeight() const;
	int getWidth() const;

	void Clear();

	Board& operator=(const Board& B);

	~Board();

	friend std::ostream& operator<< (std::ostream& out, const Board &B);
};


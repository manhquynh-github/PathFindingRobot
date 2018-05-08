#pragma once
#include "Board.h"
#include "Tree.h"
#include "Queue.h"
class AI
{
private:
	Tile **Map;
	Tile *Start, *End;
	int Height, Width;

	Tile *MoveUp(Tile *t) const;
	Tile *MoveDown(Tile *t) const;
	Tile *MoveLeft(Tile *t) const;
	Tile *MoveRight(Tile *t) const;

	Tile *Search(const Queue<TreeNode<Tile*>*> &Q, Tile *x) const;
public:
	AI();
	AI(const Board &b);

	bool Search();

	~AI();
};


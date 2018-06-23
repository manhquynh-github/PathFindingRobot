#pragma once
#include "Board.h"
#include "Tree.h"
#include "SortedQueue.h"
class AIAStar
{
private:
	Tile **Map;
	Tile *Start, *End;
	int Height, Width;

	struct AINode
	{
		AINode *cameFrom;
		Tile* tile;
		int Gcost, Hcost, F; //move cost, heuristic cost, F

		AINode(AINode *camefrom, Tile *t, float hcost) :
			cameFrom(camefrom), tile(t), Hcost(hcost)
		{
			if (!camefrom)
				Gcost = 0;
			else
				Gcost = camefrom->Gcost + 1;

			F = Gcost + Hcost;

			if (tile->Type != 'S') tile->Type = '+';
		}

		~AINode()
		{
			cameFrom = nullptr;
			tile = nullptr;
		}
	};

	struct LessAINode
	{
		bool operator() (const AINode *a, const AINode *b)
		{
			return a->F < b->F;
		}
	};

	struct EqualAINode
	{
		bool operator() (const AINode *a, const AINode *b)
		{
			return a->F == b->F;
		}
	};

	int CalculateHCost(Tile *t);

	Tile *MoveUp(Tile *t) const;
	Tile *MoveDown(Tile *t) const;
	Tile *MoveLeft(Tile *t) const;
	Tile *MoveRight(Tile *t) const;
public:
	AIAStar();
	AIAStar(const Board &b);

	bool Search();

	~AIAStar();
};


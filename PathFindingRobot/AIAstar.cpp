#include "AIAStar.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int AIAStar::CalculateHCost(Tile * t)
{
	return abs(End->x - t->x) + abs(End->y - t->y);
}

Tile* AIAStar::MoveUp(Tile *t) const
{
	if (!t || t->y == 0 || Map[t->x][t->y - 1].Type == (char)254u) return NULL;
	return &Map[t->x][t->y - 1];
}

Tile* AIAStar::MoveDown(Tile *t) const
{
	if (!t || t->y == Height - 1 || Map[t->x][t->y + 1].Type == (char)254u) return NULL;
	return &Map[t->x][t->y + 1];
}

Tile* AIAStar::MoveLeft(Tile *t) const
{
	if (!t || t->x == 0 || Map[t->x - 1][t->y].Type == (char)254u) return NULL;
	return &Map[t->x - 1][t->y];
}

Tile* AIAStar::MoveRight(Tile *t) const
{
	if (!t || t->x == Width - 1 || Map[t->x + 1][t->y].Type == (char)254u) return NULL;
	return &Map[t->x + 1][t->y];
}

AIAStar::AIAStar()
{
}

AIAStar::AIAStar(const Board &b)
{
	Map = b.getMap();
	Height = b.getHeight();
	Width = b.getWidth();
	Start = b.getStart();
	End = b.getEnd();
}

bool AIAStar::Search()
{
	Tile* TileCollection[4];
	bool found = false;
	AINode *T = new AINode(NULL, Start, CalculateHCost(Start));
	SortedQueue<AINode*, LessAINode, EqualAINode> Q;
	Q.push(T);

	while (Q.IsEmpty() == false)
	{

		AINode *now = Q.Front()->getInfo();

		TileCollection[0] = MoveUp(now->tile);
		TileCollection[1] = MoveDown(now->tile);
		TileCollection[2] = MoveLeft(now->tile);
		TileCollection[3] = MoveRight(now->tile);

		for each (Tile* t in TileCollection)
		{
			if (t && t->Checked == false && t->Type == ' ')
			{
				AINode *p = new AINode(now, t, CalculateHCost(t));
				if (p->Hcost == 1)
				{
					T = p;
					found = true;
					break;
				}
				else
				{
					Q.push(p);
				}
			}
		}

		if (found == true) break;

		now->tile->Checked = true;
		Q.pop();
	}



	if (T->Hcost != 1)
	{
		cout << "Stuck!" << endl;
		return false;
	}
	else
	{
		cout << T->Gcost + 1 << " steps." << endl;
		while (T)
		{
			if (T->tile->Type == '+')
				T->tile->Type = (char)6;

			T = T->cameFrom;
		}
		return true;
	}

	delete[] TileCollection;
}

AIAStar::~AIAStar()
{
}

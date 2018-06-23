#include "AI.h"
#include <iostream>

using namespace std;

Tile* AI::MoveUp(Tile *t) const
{
	if (!t || t->y == 0 || Map[t->x][t->y - 1].Type == (char)254u) return nullptr;
	return &Map[t->x][t->y - 1];
}

Tile* AI::MoveDown(Tile *t) const
{
	if (!t || t->y == Height - 1 || Map[t->x][t->y + 1].Type == (char)254u) return nullptr;
	return &Map[t->x][t->y + 1];
}

Tile* AI::MoveLeft(Tile *t) const
{
	if (!t || t->x == 0 || Map[t->x - 1][t->y].Type == (char)254u) return nullptr;
	return &Map[t->x - 1][t->y];
}

Tile* AI::MoveRight(Tile *t) const
{
	if (!t || t->x == Width - 1 || Map[t->x + 1][t->y].Type == (char)254u) return nullptr;
	return &Map[t->x + 1][t->y];
}

Tile * AI::Search(const Queue<TreeNode<Tile*>*> &Q, Tile * x) const
{
	if (!Q.Front() || !x) return nullptr;
	Node<TreeNode<Tile*>*> *p = Q.Front();
	while (p && p->getInfo()->getInfo() != x)
		p = p->getpNext();

	if (!p) return nullptr;
	return p->getInfo()->getInfo();
}

AI::AI()
{
}

AI::AI(const Board &b)
{
	Map = b.getMap();
	Height = b.getHeight();
	Width = b.getWidth();
	Start = b.getStart();
	End = b.getEnd();
}

bool AI::Search()
{
	TreeNode<Tile*> *T = new TreeNode<Tile*>(Start);
	Queue<TreeNode<Tile*>*> Q;

	Q.push(T);

	

	while (Q.IsEmpty() == false)
	{

		if (Q.Front()->getInfo()->getInfo()->Type == 'G')
		{
			T = Q.Front()->getInfo();
			break;
		}

		TreeNode<Tile*> *now = Q.Front()->getInfo();
		
		if (now->getInfo()->Type != 'S') now->getInfo()->Type = '+';

		Tile *up = MoveUp(now->getInfo()),
			*down = MoveDown(now->getInfo()),
			*left = MoveLeft(now->getInfo()),
			*right = MoveRight(now->getInfo());

		if (up && up->Checked == false && !Search(Q, up))
			Q.push(new TreeNode<Tile*>(up, now));
		if (Q.Last()->getInfo()->getInfo()->Type == 'G')
		{
			T = Q.Last()->getInfo();
			break;
		}
		if (down && down->Checked == false && !Search(Q, down))
			Q.push(new TreeNode<Tile*>(down, now));
		if (Q.Last()->getInfo()->getInfo()->Type == 'G')
		{
			T = Q.Last()->getInfo();
			break;
		}
		if (left && left->Checked == false && !Search(Q, left))
			Q.push(new TreeNode<Tile*>(left, now));
		if (Q.Last()->getInfo()->getInfo()->Type == 'G')
		{
			T = Q.Last()->getInfo();
			break;
		}
		if (right && right->Checked == false && !Search(Q, right))
			Q.push(new TreeNode<Tile*>(right, now));
		if (Q.Last()->getInfo()->getInfo()->Type == 'G')
		{
			T = Q.Last()->getInfo();
			break;
		}

		now->getInfo()->Checked = true;
		
		Q.pop();

	}

	

	if (T->getInfo()->Type != 'G')
	{
		cout << "Stuck!" << endl;
		return false;
	}
	else
	{
		int count = 0;
		while (T)
		{
			if (T->getInfo()->Type == '+')
				T->getInfo()->Type = (char)6;

			T = T->getFather();
			count++;
		}
		cout << count - 1 << " steps." << endl;
		return true;
	}
}

AI::~AI()
{
}

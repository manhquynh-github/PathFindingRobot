#pragma once
#include "Node.h"

template <class T, typename CmpLess, typename CmpEqual>
class SortedQueue
{
private:
	Node<T> *pHead, *min;
public:
	SortedQueue();
	~SortedQueue();

	Node<T>* push(const T &data);
	Node<T>* pop();
	Node<T>* Search(const T &data) const;
	Node<T>* Front() const;
	Node<T>* Min() const;
	bool IsEmpty() const;
};

template<class T, typename CmpLess, typename CmpEqual>
inline SortedQueue<T, CmpLess, CmpEqual>::SortedQueue()
{
	pHead = min = nullptr;
}

template<class T, typename CmpLess, typename CmpEqual>
inline SortedQueue<T, CmpLess, CmpEqual>::~SortedQueue()
{
	while (pHead)
	{
		Node<T> *p = pop();
		p->~Node<T>();
		p = nullptr;
	}
	
	if (min) min = nullptr;
}

template<class T, typename CmpLess, typename CmpEqual>
inline Node<T> * SortedQueue<T, CmpLess, CmpEqual>::push(const T &data)
{
	Node<T> *p = new Node<T>(data);
	if (p)
	{
		if (!pHead)
			pHead = min = p;
		else
		{
			CmpLess less;
			CmpEqual equal;
			if (less(data, min->getInfo()) == true)
			{
				p->setpNext(pHead);
				pHead = p;
				min = pHead;
			}
			else if (equal(data, min->getInfo()) == true)
			{
				p->setpNext(min->getpNext());
				min->setpNext(p);
				min = p;
			}
			else
			{
				Node<T> *q = nullptr;
				for (Node<T> *i = min; i && less(data, i->getInfo()) == false; q = i, i = i->getpNext());
				p->setpNext(q->getpNext());
				q->setpNext(p);
			}
		}
	}
	return p;
}

template<class T, typename CmpLess, typename CmpEqual>
inline Node<T> * SortedQueue<T, CmpLess, CmpEqual>::pop()
{
	if (!pHead) return nullptr;

	Node<T> *p = pHead;

	if (pHead == min)
		min = pHead->getpNext();

	if (!pHead->getpNext())
		pHead = nullptr;
	else
	{
		pHead = pHead->getpNext();
		p->setpNext(nullptr);
	}

	return p;
}

template<class T, typename CmpLess, typename CmpEqual>
inline Node<T>* SortedQueue<T, CmpLess, CmpEqual>::Search(const T &data) const
{
	if (!pHead || !data) return T();
	Node<T> *p = pHead;
	while (p && p->getInfo() != data)
		p = p->getpNext();

	return p;
}

template<class T, typename CmpLess, typename CmpEqual>
inline Node<T>* SortedQueue<T, CmpLess, CmpEqual>::Front() const
{
	return pHead;
}

template<class T, typename CmpLess, typename CmpEqual>
inline Node<T>* SortedQueue<T, CmpLess, CmpEqual>::Min() const
{
	return min;
}

template<class T, typename CmpLess, typename CmpEqual>
inline bool SortedQueue<T, CmpLess, CmpEqual>::IsEmpty() const
{
	return (pHead == nullptr);
}

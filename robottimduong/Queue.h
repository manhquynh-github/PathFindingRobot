#pragma once
#include "Node.h"

template <class T>
class Queue
{
private:
	Node<T> *pHead, *pTail;
public:
	Queue();
	~Queue();

	Node<T>* push(T info);
	Node<T>* pop();
	Node<T>* Search(T info) const;
	Node<T>* Front() const;
	Node<T>* Last() const;
	bool IsEmpty() const;
};

template<class T>
inline Queue<T>::Queue()
{
	pHead = pTail = NULL;
}

template<class T>
inline Queue<T>::~Queue()
{
	while (pHead)
	{
		Node<T> *p = pop();
		p->~Node<T>();
		p = NULL;
	}

	if (pTail) pTail = NULL;
}

template<class T>
inline Node<T> * Queue<T>::push(T info)
{
	Node<T> *p = new Node<T>(info);
	if (p)
	{
		if (!pHead)
			pHead = pTail = p;
		else
		{
			pTail->setpNext(p);
			pTail = p;
		}
	}
	return p;
}

template<class T>
inline Node<T> * Queue<T>::pop()
{
	if (!pHead) return NULL;
	
	Node<T> *p = pHead;
	if (pHead == pTail)
		pHead = pTail = NULL;
	else
	{
		pHead = pHead->getpNext();
		p->setpNext(NULL);
	}

	return p;
}

template<class T>
inline Node<T>* Queue<T>::Search(T info) const
{
	if(!pHead || !info) return NULL;
	Node<T> *p = pHead;
	while (p && p->getInfo() != info)
		p = p->getpNext();

	return p;
}

template<class T>
inline Node<T>* Queue<T>::Front() const
{
	return pHead;
}

template<class T>
inline Node<T>* Queue<T>::Last() const
{
	return pTail;
}

template<class T>
inline bool Queue<T>::IsEmpty() const
{
	return (pHead == NULL);
}

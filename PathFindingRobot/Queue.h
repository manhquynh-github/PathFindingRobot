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

	Node<T>* push(T data);
	Node<T>* pop();
	Node<T>* Search(T data) const;
	Node<T>* Front() const;
	Node<T>* Last() const;
	bool IsEmpty() const;
};

template<class T>
inline Queue<T>::Queue()
{
	pHead = pTail = nullptr;
}

template<class T>
inline Queue<T>::~Queue()
{
	while (pHead)
	{
		Node<T> *p = pop();
		p->~Node<T>();
		p = nullptr;
	}

	if (pTail) pTail = nullptr;
}

template<class T>
inline Node<T> * Queue<T>::push(T data)
{
	Node<T> *p = new Node<T>(data);
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
	if (!pHead) return nullptr;
	
	Node<T> *p = pHead;
	if (pHead == pTail)
		pHead = pTail = nullptr;
	else
	{
		pHead = pHead->getpNext();
		p->setpNext(nullptr);
	}

	return p;
}

template<class T>
inline Node<T>* Queue<T>::Search(T data) const
{
	if(!pHead || !data) return nullptr;
	Node<T> *p = pHead;
	while (p && p->getInfo() != data)
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
	return (pHead == nullptr);
}

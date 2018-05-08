#pragma once
template <class T>
class Node
{
private:
	T Info;
	Node *pNext;
public:
	Node();
	Node(T info);
	Node(T info, Node* pnext);
	~Node();

	Node* getpNext() const;
	void setpNext(Node* pnext);
	T getInfo() const;
	void setInfo(T info);
};

template<class T>
inline Node<T>::Node()
{
	Info = T();
	pNext = NULL;
}

template<class T>
inline Node<T>::Node(T info)
{
	Info = info;
	pNext = NULL;
}

template<class T>
inline Node<T>::Node(T info, Node * pnext)
{
	Info = info;
	pNext = pnext;
}

template<class T>
inline Node<T>::~Node()
{
	if (pNext) pNext = NULL;
	Info.~T();
}

template<class T>
inline Node<T> * Node<T>::getpNext() const
{
	return pNext;
}

template<class T>
inline void Node<T>::setpNext(Node<T> * pnext)
{
	pNext = pnext;
}

template<class T>
inline T Node<T>::getInfo() const
{
	return Info;
}

template<class T>
inline void Node<T>::setInfo(T info)
{
	Info = info;
}

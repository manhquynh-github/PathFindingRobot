#pragma once
template <class T>
class Node
{
private:
	T Data;
	Node *pNext;
public:
	Node();
	Node(T data);
	Node(T data, Node* pnext);
	~Node();

	Node* getpNext() const;
	void setpNext(Node* pnext);
	T getInfo() const;
	void setInfo(T data);
};

template<class T>
inline Node<T>::Node()
{
	Data = T();
	pNext = nullptr;
}

template<class T>
inline Node<T>::Node(T data)
{
	Data = data;
	pNext = nullptr;
}

template<class T>
inline Node<T>::Node(T data, Node * pnext)
{
	Data = data;
	pNext = pnext;
}

template<class T>
inline Node<T>::~Node()
{
	if (pNext) pNext = nullptr;
	Data.~T();
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
	return Data;
}

template<class T>
inline void Node<T>::setInfo(T data)
{
	Data = data;
}

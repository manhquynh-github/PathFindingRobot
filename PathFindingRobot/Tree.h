#pragma once
template <class T>
class TreeNode
{
private:
	T Data;
	TreeNode *Father;
	TreeNode *Child;
public:
	TreeNode();
	TreeNode(T data);
	TreeNode(T data, TreeNode *father);
	~TreeNode();

	T getInfo() const;
	TreeNode *getFather() const;
	TreeNode *getChild() const;
};

template<class T>
inline TreeNode<T>::TreeNode()
{
	Data = T();
	Father = Child = nullptr;
}

template<class T>
inline TreeNode<T>::TreeNode(T data)
{
	Data = data;
	Father = Child = nullptr;
}

template<class T>
inline TreeNode<T>::TreeNode(T data, TreeNode<T> * father)
{
	Data = data;
	Father = father;
	Child = nullptr;
}

template<class T>
inline TreeNode<T>::~TreeNode()
{
	if (Child)
		Child = nullptr;
	if (Father)
		Father = nullptr;

	Data.~T();
}

template<class T>
inline T TreeNode<T>::getInfo() const
{
	return Data;
}

template<class T>
inline TreeNode<T> * TreeNode<T>::getFather() const
{
	return Father;
}

template<class T>
inline TreeNode<T> * TreeNode<T>::getChild() const
{
	return Child;
}


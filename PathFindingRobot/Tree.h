#pragma once
template <class T>
class TreeNode
{
private:
	T Info;
	TreeNode *Father;
	TreeNode *Child;
public:
	TreeNode();
	TreeNode(T info);
	TreeNode(T info, TreeNode *father);
	~TreeNode();

	T getInfo() const;
	TreeNode *getFather() const;
	TreeNode *getChild() const;
};

template<class T>
inline TreeNode<T>::TreeNode()
{
	Info = T();
	Father = Child = nullptr;
}

template<class T>
inline TreeNode<T>::TreeNode(T info)
{
	Info = info;
	Father = Child = nullptr;
}

template<class T>
inline TreeNode<T>::TreeNode(T info, TreeNode<T> * father)
{
	Info = info;
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

	Info.~T();
}

template<class T>
inline T TreeNode<T>::getInfo() const
{
	return Info;
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


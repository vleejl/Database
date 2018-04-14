#ifndef BPLUS_H_
#define BPLUS_H_
#include "BPNode.h"
#include "BPLeafNode.h"
#include "BTree.h"

//key值比child值少一个
//(m/2, m)个关键值
//（m/2+1，m+1）个子树
template <typename Key, typename E>
class BPlus : BTree<Key, E>
{
public:
	BPlus(): _order(0), _size(0), _rootPtr(new BPNormalNode<Key, E>()), _currentPtr(_rootPtr), _rootLeafNode(new BPLeafNode()) {}
	BPlus(const int& capacity) : _order(capacity), _size(0), _rootPtr(new BPNormalNode<Key, E>()),
		_currentPtr(_rootPtr), _rootLeafNode(new BPLeafNode()) {}
	BPlus(const BPlus&) = delete;
	BPlus& operator=(const BPlus&) = delete;

	std::shared_ptr<E> search(const Key&);
	void insert(Key&, E*);
	std::shared_ptr<E> remove(const Key&);
	~BPlus();
private:
	void mergeLeaf(BPNode<Key, E>*, BPNode<Key, E>*, bool);
	void solveOverflow(BPNode<Key, E>*, bool);
	void solveUnderflow(BPNode<Key, E>*, bool);
	void init();
private:
	int _order;//关键值的数量
	int _size;//B+树总的关键值数量
	BPNode<Key, E>* _rootPtr;
	BPNode<Key, E>* _currentPtr;
	BPNode* _rootLeafNode;
};

//简单工厂模式
template <typename Key, typename E>
BPNode<Key, E>* getBPNode(bool isLeaf)
{
	if (isLeaf)
		return new BPLeafNode<Key, E>();
	else
		return new BPNormalNode<Key, E>();
}
#endif // !BPLUS_H_
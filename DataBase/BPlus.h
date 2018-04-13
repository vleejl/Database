#ifndef BPLUS_H_
#define BPLUS_H_

#include "BPNode.h"
#include "BTree.h"

template <typename Key, typename E>
class BPlus : BTree<Key, E>
{
public:
	BPlus(): _capacity(0), _rootPtr(new BPNode<Key, E>()), _currentPtr(_rootPtr) {}
	BPlus(const size_t& capacity) : 
		_capacity(capacity), _rootPtr(new BPNode<Key, E>()), _currentPtr(_rootPtr) {}

	BPlus(const BPlus&) = delete;
	BPlus& operator=(const BPlus&) = delete;

	std::shared_ptr<E> search(const Key&);
	void insert(const Key&, const std::shared_ptr<E>);
	void remove(const Key& key);
	~BPlus();
private:
	size_t _capacity;//节点的最大数量,一定是第一个被初始化
	typedef typename std::shared_ptr<BPNode<Key, E>> Ptr;
	BPNode<Key, E>* _rootPtr;
	Ptr _currentPtr;
};

#endif // !BPLUS_H_
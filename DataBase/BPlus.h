#pragma once
#include "BTree.h"
#include "BPNode.h"

template <typename Key, typename E>
class BPlus : BTree<Key, E>
{
public:
	std::shared_ptr<E> search(const Key&);
	void insert(const Key&, const std::shared_ptr<E>);
	void remove(const Key& key);
public:
	class BPRootNode : public BPNode<Key, E>
	{
	public:
		BPRootNode() : BPNode<Key, E>(false, _capacity) {}
	};

	class BPNormalNode : public BPNode<Key, E>
	{
	public:
		BPRootNode() : BPNode<Key, E>(false, _capacity) {}
	};

	class BPLeafNode : public BPNode<Key, E>
	{
	typedef std::shared_ptr<BPNode<Key, E>> LinkPtr;

	public:
		BPRootNode() : BPNode<Key, E>(true, _capacity) {}
	private:
		LinkPtr _leftPtr;
		LinkPtr _rightPtr;
	};
private:
	size_t _capacity;//节点的最大数量
};
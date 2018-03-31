#include "BPNode.h"

template <typename Key, typename E>
void BPNode<Key, E>::Pair::helpCopy(const Pair& pair)
{
	this->_keyPtr = pair->_keyPtr;
	this->_ptr = pair->_ptr;
}

template <typename Key, typename E>
BPNode<Key, E>::Pair::Pair(const Pair& pair)
{
	helpCopy(pair);
}

template <typename Key, typename E>
typename BPNode<Key, E>::Pair& BPNode<Key, E>::Pair::operator=(const Pair& pair)
{
	helpCopy(pair);
	return *this;
}

template <typename Key, typename E>
void BPNode<Key, E>::Pair::setValue(const std::shared_ptr<Key> keyPtr)
{
	this->_keyPtr = keyPtr;
}

template <typename Key, typename E>
std::shared_ptr<Key> BPNode<Key, E>::Pair::getKey()
{
	return _keyPtr;
}

template <typename Key, typename E>
std::shared_ptr<E> BPNode<Key, E>::Pair::getPtr()
{
	return _ptr;
}

template <typename Key, typename E>
void BPNode<Key, E>::helpCopy(const BPNode& bpNode)
{
	this->_ptrPairs = bpNode->_ptrPairs;
	this->isLeaf = bpNode->isLeaf;
	this->_capacity = bpNode->_capacity;
}

template <typename Key, typename E>
BPNode<Key, E>::BPNode(const BPNode& bpNode)
{
	helpCopy(bpNode);
}

template <typename Key, typename E>
BPNode<Key, E>& BPNode<Key, E>::operator=(const BPNode& bpNode)
{
	helpCopy(bpNode);
	return *this;
}

/*
template <typename Key, typename E>
void BPNode<Key, E>::insert(const Key& key, const E& ptr)
{
	auto ptrKey = std::make_shared<Key>(key);
	auto ptrValue = std::make_shared<E>(elem);
	auto ptrPair = std::make_shared<Pair>();
}
*/

template <typename Key, typename E>
bool BPNode<Key, E>::isLeaf() const
{
	return this->_isLeaf;
}

template <typename Key, typename E>
bool BPNode<Key, E>::isFull() const
{
	return _capacity == _ptrPairs.size();
}

template <typename Key, typename E>
int BPNode<Key, E>::numrecs() const
{
	return _ptrPairs.size();
}
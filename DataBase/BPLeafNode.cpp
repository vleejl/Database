#include "BPLeafNode.h"

template <typename Key, typename E>
void BPLeafNode<Key, E>::setLeftLeaf(BPNode* leftPtr)
{
	_leftPtr = leftPtr;
}

template <typename Key, typename E>
void BPLeafNode<Key, E>::setRightLeaf(BPNode* rightPtr)
{
	_rightPtr = rightPtr;
}

template<typename Key, typename E>
void BPLeafNode<Key, E>::setNextLeaf(BPNode* lhs, BPNode* rhs)
{
	_leftPtr = lhs;
	_rightPtr = rhs;
}

template<typename Key, typename E>
BPNode * BPLeafNode<Key, E>::getLeftLeaf(BPNode* )
{
	return _leftPtr;
}

template<typename Key, typename E>
BPNode * BPLeafNode<Key, E>::getRightLeaf(BPNode *)
{
	return _rightPtr;
}

template <typename Key, typename E>
void BPLeafNode<Key, E>::insertChild(const E& childElem, const int& pos)
{
	_ptrELementList->moveToPos(pos);
	E* ptr = new E();
	_ptrELementList->insert(ptr);
}

template <typename Key, typename E>
BPLeafNode<Key, E>::~BPLeafNode()
{
	helpDeletePtr(_leftPtr);
	helpDeletePtr(_rightPtr);
	int size = _ptrELementList->length();
	for (int i = 0; i != size; ++i)
	{
		helpDeletePtr((*_ptrELementList)[i]);
	}
}

template <typename Key, typename E>
E* BPLeafNode<Key, E>::getChildElement(const int& pos)
{
	if (pos<0 || pos>_ptrELementList->length())
		throw - 1;
	return (*_ptrELementList)[pos];
}

template<typename Key, typename E>
int BPLeafNode<Key, E>::getChildListLength() const
{
	return _ptrELementList->length();
}

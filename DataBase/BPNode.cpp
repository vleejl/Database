#include "BPNode.h"

template <typename Key, typename E>
void BPNode<Key, E>::insertKey(const Key& key, const int& pos)
{
	_ptrKeyList->moveToPos(pos);
	_ptrKeyList->insert(key);
}

template <typename Key, typename E>
Key BPNode<Key, E>::removeKey(const int& pos)
{
	_ptrKeyList->moveToPos(pos);
	Key key = _ptrKeyList->remove();
	return key;
}

template <typename Key, typename E>
int BPNode<Key, E>::searchKey(const Key& key)
{
	int size = _ptrKeyList->length();
	int i = 0;
	for (; i != size; ++i)
	{
		if (key <= (*_ptrKeyList)[i])//节点所指向的key值都是子节点key值的最大值
		{
			return i;
		}
	}
	return i;
}

template<typename Key, typename E>
Key BPNode<Key, E>::getKey(const int& pos)
{
	return (*_ptrKeyList)[pos];
}

template<typename Key, typename E>
int BPNode<Key, E>::getKeyListLength() const
{
	return _ptrKeyList->length();
}

template<typename Key, typename E>
void BPNode<Key, E>::setParentPtr(BPNode* ptr)
{
	_parentPtr = ptr;
}

template<typename Key, typename E>
BPNode * BPNode<Key, E>::getParentPtr() const
{
	return _parentPtr;
}

template <typename Key, typename E>
bool BPNode<Key, E>::isLeaf() const
{
	return _isLeaf;
}

template <typename Key, typename E>
BPNode<Key, E>::~BPNode()
{
	helpDeletePtr(_parentPtr);
	helpDeletePtr(_ptrKeyList);	
}


//BPNormalNode
template<typename Key, typename E>
BPNormalNode<Key, E>::~BPNormalNode()
{
	int sizeChildList = _ptrChildList->length();
	for (int i = 0; i != sizeChildList; ++i)//删除孩子节点所指的内存
	{
		if ((*_ptrChildList)[i] != nullptr)
			helpDeletePtr((*_ptrChildList)[i]);
	}
	helpDeletePtr(_ptrChildList);
}

template<typename Key, typename E>
void BPNormalNode<Key, E>::insertPtrChild(const PtrBPNode& ptrBPNode, const int& pos)
{
	_ptrChildList->moveToPos(pos);
	_ptrChildList->insert(ptrBPNode);
}

template <typename Key, typename E>
void BPNormalNode<Key, E>::insertChild(const E& childKey, const int& pos)
{
	_ptrChildList->moveToPos(pos);
	BPNode::PtrBPNode ptr = new BPNormalNode<Key, E>(childKey);
	_ptrChildList->insert(ptr);
}

template <typename Key, typename E>
BPNode<Key, E>* BPNormalNode<Key, E>::getPtrChild(const int& pos)
{
	return (*_ptrChildList)[pos];
}

template<typename Key, typename E>
int BPNormalNode<Key, E>::getChildListLength() const
{
	return _ptrChildList->length();
}

template<typename Key, typename E>
BPNode<Key, E>* BPNormalNode<Key, E>::removePtrChild(const int& pos)
{
	_ptrChildList->moveToPos(pos);
	BPNode<Key, E>* ptrBPNode = _ptrChildList->remove();
	return bpNode;
}
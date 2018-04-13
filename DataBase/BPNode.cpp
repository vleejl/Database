#include "BPNode.h"

template <typename Key, typename E>
void BPNode<Key, E>::insertKey(const Key& key, const int& pos)
{
	_ptrKeyList->moveToPos(pos);
	_ptrKeyList->insert(key);
}

template <typename Key, typename E>
void BPNode<Key, E>::insertChild(const PtrBPNode& childEle, const int& pos)
{
	_ptrChildList->moveToPos(pos);
	_ptrChildList->insert(childEle);
}

template <typename Key, typename E>
Key BPNode<Key, E>::removeKey(const int& pos)
{
	_ptrKeyList->moveToPos(pos);
	Key key = _ptrKeyList->remove();
	return key;
}

template<typename Key, typename E>
BPNode<Key, E>* BPNode<Key, E>::removeChild(const int& pos)//typedef要求类型明确，但是这里类型并不明确
{
	_ptrChildList->moveToPos(pos);
	BPNode<Key, E>* ptrBPNode = _ptrChildList->remove();
	return ptrBPNode;
}

template <typename Key, typename E>
int BPNode<Key, E>::searchKey(const Key& key)
{
	int size = _ptrKeyList->length();
	int i = 0;
	for (; i != size; ++i)
	{
		if (key <= _ptrKeyList[i])
		{
			return (i - 1);
		}
	}
	return (i - 1);
}

template <typename Key, typename E>
const List<Key>* BPNode<Key, E>::getPtrKeyList() const
{
	return _ptrKeyList;
}

template <typename Key, typename E>
const List<BPNode<Key, E>::PtrBPNode>* BPNode<Key, E>::getPtrChildList() const
{
	return _ptrChildList;
}

template <typename Key, typename E>
BPNode<Key, E>::~BPNode()
{
	helpDeletePtr(_parentPtr);
	helpDeletePtr(_ptrKeyList);
	int sizeChildList = _ptrChildList->length();
	for (int i = 0; i != sizeChildList; ++i)//删除孩子节点所指的内存
	{
		if (_ptrChildList[i] != nullptr)
			helpDeletePtr(_ptrChildList[i]);
	}	
	helpDeletePtr(_ptrChildList);
}
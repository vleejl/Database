#include "BPlus.h"

template <typename Key, typename E>
std::shared_ptr<E> BPlus<Key, E>::search(const Key& key)
{
	BPNode<Key, E>* tempPtr = _rootPtr;	
	while (tempPtr->getPtrChildList() != nullptr)
	{
		int pos = tempPtr->searchKey(key);
		tempPtr = _rootPtr->getPtrChildList[i];
	}

}

template <typename Key, typename E>
void BPlus<Key, E>::insert(const Key&, const std::shared_ptr<E>)
{

}

template <typename Key, typename E>
void BPlus<Key, E>::remove(const Key& key)
{

}

template <typename Key, typename E>
BPlus<Key, E>::~BPlus()
{
	if (_rootPtr != nullptr)
		delete _rootPtr;
	_rootPtr = nullptr;
}
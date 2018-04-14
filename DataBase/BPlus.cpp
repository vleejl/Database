#include "BPlus.h"


template<typename Key, typename E>
void BPlus<Key, E>::init()
{

}

template <typename Key, typename E>
std::shared_ptr<E> BPlus<Key, E>::search(const Key& key)
{
	_currentPtr = _rootPtr;
	while (!_currentPtr->isLeaf())
	{
		int pos = _currentPtr->searchKey(key);
		_currentPtr = _currentPtr->getPtrChild(pos);//这里的pos保证不会越界
	}
	int pos = _currentPtr->searchKey(key);//到了叶子节点
	if ((pos != -1) && _currentPtr->getKey(pos) == key)
	{
		E* tempElementPtr = _currentPtr->getChildElement(pos);
		std::shared_ptr<E> ptr(tempElementPtr);
		tempElementPtr = nullptr;
		return ptr;
	}
	else
		return nullptr;
}

//关键字的插入总是有序的
template <typename Key, typename E>
void BPlus<Key, E>::insert(const Key& key, E* ptrElem)
{
	auto ptrElem = search(key);
	if (ptrElem != nullptr)
	{
		cout << "The element has already exist" << endl;
		return;
	}
	int pos = _currentPtr->searchKey(key);//此时已处于叶子节点
	_currentPtr->insertKey(key, pos);//插入到已存在的关键码之前
	_currentPtr->insertChild(ptrElem, pos);//叶子节点关键码数量和值数量相同
	++_size;
	solveOverFlow(_currentPtr, true);
}

template <typename Key, typename E>
void BPlus<Key, E>::solveOverflow(BPNode<Key, E>* nodePtr, bool isLeaf)
{
	if (nodePtr->getChildListLength() < (_order + 1)) return;//不需要解决上溢问题
	int midOrder = (_order + 1) / 2;
	BPNode<Key, E>* childPtr = getBPNode(isLeaf);
	for (int i = midOrder, j = 0; i != (_order + 1); ++i, ++j)
	{
		childPtr->insertKey(nodePtr->removeKey(i), j);
		if (isLeaf)
			childPtr->insertChild(nodePtr->removeChild(i), j);
		else
			childPtr->insertPtrChild(nodePtr->removeChild(i), j);
	}
	if (isLeaf)
		childPtr->setNextLeaf(nodePtr->getLeftLeaf(), nodePtr->getRightLeaf());//设置左右节点	
	BPNode<Key, E>* parentPtr = nodePtr->getParentPtr();
	childPtr->setParentPtr(parentPtr);
	int pos = parentPtr->searchKey(childPtr->getKey(0));
	parentPtr->insertKey(childPtr->getKey(0), pos);
	parentPtr->insertPtrChild(childPtr, pos);
	return solveOverflow(parentPtr, parentPtr->isLeaf());
}
//内部节点的关键码索引不需要删除
template <typename Key, typename E>
std::shared_ptr<E> BPlus<Key, E>::remove(const Key& key)
{
	auto ptrElem = search(key);
	if (ptrElem == nullptr)
	{
		cout << "The element dosen't exist" << endl;
		return;
	}
	int pos = _currentPtr->searchKey(key);//此时已处于叶子节点
	_currentPtr->removeKey(pos);
	E* tempElementPtr = _currentPtr->removeChild(pos);
	std::shared_ptr<E> ptr(tempElementPtr);
	tempElementPtr = nullptr;
	--_size;
	solveUnderflow(_currentPtr, true);
	return ptr;
}

template <typename Key, typename E>
void BPlus<Key, E>::mergeLeaf(BPNode<Key, E>* ptr, BPNode<Key, E>* operatedPtr, bool isRight)
{
	int size = ptr->getKeyListLength();
	int insertPos = isRight ? operatedPtr->getKeyListLength() - 1 : 0;
	operatedPtr->insertKey(ptr->removeKey(size - 1), insertPos);
	operatedPtr->insertPtrChild(ptr->removeChild(size - 1), insertPos);
}

template <typename Key, typename E>
void BPlus<Key, E>::solveUnderflow(BPNode<Key, E>* nodePtr, bool isLeaf)
{
	int midOrder = (_order + 1) / 2; 
	if (nodePtr->getChildListLength() >= midOrder) 
		return;//不需要解决下溢问题	
	if (isLeaf)
	{

	}
	if ((nodePtr->getLeftLeaf()->getKeyListLength()) > midOrder)//从左兄弟处借去
	{
		mergeLeaf(nodePtr->getLeftLeaf(), nodePtr, false);
	}
	else if ((nodePtr->getRightLeaf()->getKeyListLength()) > midOrder)
	{
		mergeLeaf(nodePtr->getRightLeaf(), nodePtr, true);;
	}
	else//与右边兄弟节点合并
	{
		int size = nodePtr->getKeyListLength();
		BPNode<Key, E>* rightPtr = nodePtr->getRightLeaf();
		for (int i = szie - 1; i >= 0; --i)
		{
			mergeLeaf(nodePtr, rightPtr, false);
		}
	}
}

template <typename Key, typename E>
BPlus<Key, E>::~BPlus()
{
	if (_rootPtr != nullptr)
		delete _rootPtr;
	_rootPtr = nullptr;
}
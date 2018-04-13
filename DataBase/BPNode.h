#ifndef BPNODE_H_
#define BPNODE_H_
#include "List.h"
#include "LList.h"

template <typename T>
void helpDeletePtr(T& ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}


template <typename Key, typename E>
class BPNode
{
public:
	typedef BPNode<Key, E>* PtrBPNode;
	BPNode() :_parentPtr(nullptr), _ptrKeyList(new LList<Key>()), _ptrChildList(nullptr) {}
	BPNode(const Key& key, const PtrBPNode& rhs, const PtrBPNode& lhs) :
		_parentPtr(nullptr)
	{
		_ptrKeyList->apend(key);
		_ptrChildList->apend(rhs);
		_ptrChildList->apend(lhs);
	}
	virtual void insertKey(const Key&, const int&);
	virtual void insertChild(const PtrBPNode&, const int&);
	virtual Key removeKey(const int&);
	virtual BPNode<Key, E>* removeChild(const int&);
	virtual int searchKey(const Key&);
	virtual const List<Key>* getPtrKeyList() const;
	virtual const List<PtrBPNode>* getPtrChildList() const;
	virtual ~BPNode();
private:
	BPNode* _parentPtr;
	List<Key>* _ptrKeyList;
	List<PtrBPNode>* _ptrChildList;
};


#endif // !BPNODE_H_


#ifndef BPLEAFNODE_H_
#define BPLEAFNODE_H_

template <typename Key, typename E>
class BPLeafNode : public BPNode<Key, E>
{
private:
	bool _isLeaf;
	BPLeafNode*  _ptrLeft;
	BPLeafNode*  _ptrRight;
};


#endif // !BPLEAFNODE_H_
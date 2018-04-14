#ifndef BPNODE_H_
#define BPNODE_H_
#include "List.h"
#include "LList.h"
#include <iostream>

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
	BPNode() :_parentPtr(nullptr), _isLeaf(false), _ptrKeyList(new LList<Key>()) {}
//	BPNode(BPNode* parentPtr) :_parentPtr(parentPtr), _isLeaf(false), _ptrKeyList(new LList<Key>()) {}
	BPNode(bool isLeaf) :_parentPtr(nullptr), _isLeaf(isLeaf), _ptrKeyList(new LList<Key>()) {}
	BPNode(const Key& key, bool isLeaf = false) : _parentPtr(nullptr), _isLeaf(false), _ptrKeyList(new LList<Key>())
	{
		_ptrKeyList->apend(key);
	}
	virtual void insertKey(const Key&, const int&);	
	virtual Key removeKey(const int&);
	virtual int searchKey(const Key&);	
	virtual Key getKey(const int&);
	virtual int getKeyListLength() const;
	virtual void setParentPtr(BPNode*);
	virtual BPNode* getParentPtr() const;
	virtual bool isLeaf() const;
	virtual ~BPNode();

	virtual int getChildListLength() const = 0;
	virtual E* getChildElement(const int&) = 0;//获取叶子节点指向的value值
	virtual void insertChild(const E&, const int&) = 0;
	virtual void setNextLeaf(BPNode*, BPNode*) = 0;
	virtual BPNode* getLeftLeaf(BPNode*) = 0;
	virtual BPNode* getRightLeaf(BPNode*) = 0;
	virtual E* removeChild(const int&) = 0;

	virtual void insertPtrChild(const PtrBPNode&, const int&) = 0;
	virtual PtrBPNode getPtrChild(const int&) = 0;//获取内部节点指向的子节点
	virtual PtrBPNode removePtrChild(const int&) = 0;
	
protected:
	BPNode* _parentPtr;
	bool _isLeaf;
	List<Key>* _ptrKeyList;
	
	virtual void helpError()
	{
		std::cout << "You have the wrong error operation" << std::endl;
	}
};

#endif // !BPNODE_H_

#ifndef BPNORMALNODE_H_
#define BPNORMALNODE_H_
template <typename Key, typename E>
class BPNormalNode : public BPNode<Key, E>
{
public:
	BPNormalNode(): BPNode(), _ptrChildList(new LList<PtrBPNode>()) {}
	BPNormalNode(const Key& key) : BPNode(key), _ptrChildList(new LList<PtrBPNode>()) {}
	BPNormalNode(const Key& key, const PtrBPNode& rhs, const PtrBPNode& lhs) :
		: BPNode(key), _ptrChildList(new LList<PtrBPNode>())
	{
		_ptrChildList->apend(rhs);
		_ptrChildList->apend(lhs);
	}
	~BPNormalNode();
	void insertPtrChild(const PtrBPNode&, const int&) override;	
	BPNode<Key, E>* getPtrChild(const int&) override;
	int getChildListLength() const override;
	PtrBPNode removePtrChild(const int&) override;
private:
	E* removeChild(const int&) 
	{ 
		helpError(); 
		return nullptr;
	}
	E* getChildElement(const int&) 
	{
		helpError();
		return nullptr;
	}
	void insertChild(const E&, const int&) override { return helpError(); }
	void setRightLeaf(BPNode*) { return helpError(); }
	void setLeftLeaf(BPNode*) { return helpError(); }	

	List<PtrBPNode>* _ptrChildList;
};
#endif // !BPNORMALNODE_H_

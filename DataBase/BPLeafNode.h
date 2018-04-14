#ifndef BPLEAFNODE_H_
#define BPLEAFNODE_H_
#include "BPNode.h"


template <typename Key, typename E>
class BPLeafNode : public BPNode<Key, E>
{
public:
	BPLeafNode() : BPNode(true), _ptrELementList(new LList<E*>()), 
		_leftPtr(nullptr), _rightPtr(nullptr) {}
	BPLeafNode(const Key& key, BPLeafNode* leftPtr = nullptr, BPLeafNode* rightPtr = nullptr) :
		BPNode(key), _ptrELementList(new LList<E*>()), _leftPtr(leftPtr), _rightPtr(rightPtr) {}
	void setNextLeaf(BPNode*, BPNode*) override;
	BPNode* getLeftLeaf(BPNode*) override;
	BPNode* getRightLeaf(BPNode*) override;
	void insertChild(const E&, const int&) override;

	E* getChildElement(const int&) override;
	int getChildListLength() const;
private:
	PtrBPNode removePtrChild(const int& pos) override
	{
		helpError();
		return nullptr;
	}
	E* removeChild(const int& pos) override
	{
		helpError();
		return nullptr;
	}
	PtrBPNode getPtrChild(const int& pos) override
	{
		helpError();
		return nullptr;
	}
	~BPLeafNode();
private:
	List<E*>* _ptrELementList;
	BPNode* _leftPtr;
	BPNode* _rightPtr;	
};

#endif // !BPLEAFNODE_H_
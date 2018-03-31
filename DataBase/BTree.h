#pragma once
#include <memory>

//为降低复杂度，禁止拷贝初始化、=操作运算符
//这是一个规范B+树的接口
template<typename Key, typename E>
class BTree
{
public:
	BTre() {}
	~BTree() {}
	BTree(const BTree&) = delete;
	BTree(const BTree&&) = delete;
	BTree& operator = (const BTree&) = delete;
	BTree& operator = (const BTree&&) = delete;

	virtual std::shared_ptr<E> search(const Key&) = 0;
	virtual void insert(const Key&, const std::shared_ptr<E>) = 0;
	virtual void remove(const Key& key) = 0;
};
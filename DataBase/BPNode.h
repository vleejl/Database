#pragma once
#include <list>
#include <memory>

//假设B+树关键字数量和孩子指针数量相同

template <typename Key, typename E>
class BPNode
{	
public:
	class Pair
	{
	public:
		Pair() :_childPtr(nullptr) {}//默认关键字的数据类型会提供数据初始化
		Pair(const std::shared_ptr<Key>& keyPtr = nullptr, const std::shared_ptr<E>& ptr = nullptr)
			:_keyPtr(keyPtr), _ptr(ptr) {}
		Pair(const Pair&);
		Pair& operator=(const Pair&);
		Pair(const Pair&&) = delete;
		Pair& operator=(const Pair&&) = delete;
		void setValue(const std::shared_ptr<Key> keyPtr);
		std::shared_ptr<Key> getKey();
		std::shared_ptr<E> getPtr();
		~Pair() {}
	private:
		void helpCopy(const Pair&);
	private:
		std::shared_ptr<Key> _keyPtr;
		std::shared_ptr<E> _ptr;
	};
protected://方便子类调用
	typedef typename std::list<std::shared_ptr<Pair>> PtrPair;
	//节点当前的数量就是list中Pair对象的数量
	PtrPair _ptrPairs;
	bool _isLeaf;
	//该节点的最大容量
	size_t _capacity;
public:
	BPNode() :_ptrPairs(new PtrPair()), isLeaf(false), _capacity(0) {}
	BPNode(const bool& isLeaf, const size_t& capacity = 0) :_ptrPairs(new PtrPair()),
		_isLeaf(isLeaf), _capacity(capacity) {}//规定：创建节点时需要指定其属性
	BPNode(const BPNode&);
	BPNode& operator=(const BPNode&);
	BPNode(const BPNode&&) = delete;
	BPNode& operator=(const BPNode&&) = delete;
	virtual ~BPNode() {}
	//插入行为永远只在叶子节点发生
	virtual void insert(const Key& key, const E& ptr) = 0;//在节点内部插入pair，默认调用者会事先调用full函数
	virtual bool isLeaf() const = 0;//当前节点是否为叶子节点
	virtual bool isFull() const = 0;//当前节点的记录数量是否为满
	virtual int numrecs() const = 0;//当前记录的数量
	//virtual std::shared_ptr<Key> getKeysArray() const {}//返回关键字数组指针
private:
	void helpCopy(const BPNode& bpNode);
};
#ifndef LINK_H_
#define LINK_H_

template <typename E>
class Link
{
public:
	E element;
	Link *next;
	Link(const E &elemval, Link *nextval = nullptr) :element(elemval), next(nextval) {}
	Link(Link *nextval = nullptr) :next(nextval) {}
	void* operator new(size_t)
	{
		if (freeList == nullptr)
			return ::new Link;
		Link<E> *temp = freeList;
		freeList = freeList->next;
		return temp;
	}
	void operator delete(void *ptr)
	{
		(static_cast<Link<E>*>(ptr))->next = freeList;
		freeList = static_cast<Link<E>*>(ptr);
	}
private:
	static Link<E> *freeList;
};
//如果在类外初始化，则违反了静态成员只属于类的全体成员这一约定
template <typename E>
Link<E> *Link<E>::freeList = nullptr;
#endif // !LINK_H_

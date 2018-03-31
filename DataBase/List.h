#ifndef LIST_H_
#define LIST_H_

template <typename Elem>
class List
{
public:
	List() {}
	virtual ~List() {}
	virtual void clear() = 0;
	virtual void insert(const Elem&) = 0;
	virtual void apend(const Elem&) = 0;
	virtual Elem remove() = 0;
	virtual void moveToStart() = 0;
	virtual void moveToEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int length() const = 0;
	virtual int curPos() const = 0;
	virtual void moveToPos(int pos) = 0;
	virtual const Elem& getValue() const = 0;
private:
	//void operate=(const List&) {}
	List(const List&) {}
};
#endif // !LIST_H_
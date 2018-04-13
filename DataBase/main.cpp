#include <iostream>
#include "BPlus.h"
#include "BPlus.cpp"
using namespace std;

int main()
{
	BPlus<int, int>* ptr = new BPlus<int, int>();
	ptr->search(10);
	delete ptr;
	std::cout << std::endl;
	system("pause");
	return 0;
}
















/*
template <typename Key>
class TestA
{
public:
	class TestB
	{
	public:
		void help()
		{
			std::cout << "The help function is called" << std::endl;
		}
		TestB() {}
		TestB(int i) : _i(i)
		{
			std::cout << "TestB is called" << std::endl;
		}
	private:
		Key _i;
	};
public:
	TestA(Key value) : _value(value), _valueB(TestB(value)), ptr1(new TestB()), ptr2(new LList<std::shared_ptr<TestB>>())//, _ptr(new Ptr())
	{
		TestB temp;
		temp = (_valueB);
		std::cout << "TestA is called" << ptr2.length() << std::endl;
	}
	void testFun()
	{
		std::cout << "³¤¶ÈÎª£º" << _ptr->length() << std::endl;
		//_ptr1->clear();
	}

private:
	Key _value;
	TestB _valueB;
	typedef typename std::shared_ptr<TestB> TypeB;
	typedef typename std::shared_ptr<LList<TypeB>> Ptr;
	Ptr _ptr;
	std::shared_ptr<TestB> ptr1;
	LList<std::shared_ptr<TestB>>  ptr2;
};
*/
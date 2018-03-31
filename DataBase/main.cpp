#include <iostream>s

int main()
{
	std::cout << std::endl;
	system("pause");
	return 0;
}


/*
template <typename Key>
class TestA
{
public:
TestA(Key value) : _value(value), _valueB(TestB(value)), _ptr(new TestB(value))
{
TestB temp;
temp = (_valueB);
cout << "TestA is called" << endl;
}
void testFun()
{
_ptr;
_ptr1->clear();
}
class TestB
{
public:
void help()
{
cout << "The help function is called" << endl;
}
TestB() {}
TestB(int i) : _i(i)
{
cout << "TestB is called" << endl;
}
private:
Key _i;
};
private:
Key _value;
TestB _valueB;
typedef typename std::shared_ptr<TestB> TypeB;
std::shared_ptr<LList<TypeB>> _ptr;
LList<TypeB> *rawPtr;
std::shared_ptr<LList<int>> _ptr1;
std::list<TypeB> _ptr3;
};
*/
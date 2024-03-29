// Full_ptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include "full_ptr.h"
using namespace std;

class test {
public:
	test(char c):c(c) {}
	void show()
	{
		std::cout << "调用了打印函数:" << c << std::endl;
	}
	~test()
	{
		std::cout << "删除:" << c << std::endl;
	}
private:
	char c;
};

template<typename T>
class p1
{
public:
	p1(full_ptr<T> & data) :_data(&data)
	{
	}
	p1<T> * next;
	full_ptr<T> * _data;
};

void CircleAround()
{
	full_ptr<test> a(new test('a'));
	std::cout << "创建两个结点并互相引用" << std::endl;
	p1<test> f1(a);
	p1<test> f2(a);
	f1.next = &f2;
	f2.next = &f2;
	(*f1._data)->show();
	(*f2._data)->show();
	std::cout << "函数执行结束" << std::endl;
}
void SetNullptr()
{
	full_ptr<test> a = new test('a');
	full_ptr<test> b = a;
	full_ptr<test> c = new test('c');
	std::cout << "开始：" << std::endl;
	c = a;
	a->show();
	b->show();

	std::cout << "a赋值为空后：" << std::endl;
	a = nullptr;
	std::cout << "b赋值为空后：" << std::endl;
	b = nullptr;

	std::cout << "c局部变量被被销毁后：" << std::endl;
	return;
}
void main()
{
	SetNullptr();
	CircleAround();
	cin.get();
}

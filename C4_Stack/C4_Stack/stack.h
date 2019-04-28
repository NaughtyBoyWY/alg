#pragma once
#include<iostream>
using namespace std;
const int MaxSize = 20;
/****************************************************
数据结构：栈
成员：
	int elem[MaxSize];
	int size;
函数：
	入栈
	出栈
	栈是否为空
	返回元素个数
	返回栈顶元素
****************************************************/
class MyStack
{
public:
	MyStack();
	~MyStack();

	bool Push(int elem);
	bool Pop();
	bool IsEmpty();
	int Size();
	bool Top(int& top);
private:
	int m_elem[MaxSize];
	int m_size;
};


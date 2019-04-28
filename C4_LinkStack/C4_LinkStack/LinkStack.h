#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode* pt;
};
/**************************************************
数据结构：链栈
成员：
	LinkNode* m_top;
	int m_size;
函数：
	入栈
	出栈
	返回数量
	清空栈
**************************************************/
class LinkStack
{
public:
	LinkStack();
	~LinkStack();

	void Push(int elem);
	bool Pop();
	int Size();
	bool DelStack();
	void Show();
private:
	LinkNode* m_top;
	int m_size;
};

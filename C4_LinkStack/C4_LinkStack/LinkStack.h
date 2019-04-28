#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode* pt;
};
/**************************************************
���ݽṹ����ջ
��Ա��
	LinkNode* m_top;
	int m_size;
������
	��ջ
	��ջ
	��������
	���ջ
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

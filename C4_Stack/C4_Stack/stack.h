#pragma once
#include<iostream>
using namespace std;
const int MaxSize = 20;
/****************************************************
���ݽṹ��ջ
��Ա��
	int elem[MaxSize];
	int size;
������
	��ջ
	��ջ
	ջ�Ƿ�Ϊ��
	����Ԫ�ظ���
	����ջ��Ԫ��
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


#pragma once
#include<iostream>
#include<random>
#include<ctime>
using namespace std;
/********************************************
��ͷ�ڵ�ĵ�������
��Ա��
	LinkNode*	front
	int			size
ʵ�ֹ��ܣ�
	�������һ������Ϊn������ͷ�巨��
	�������һ������Ϊn������β�巨��
	���������ȡ
	����Ԫ�ض�ȡ
	����ɾ��
	����ָ��λ�ò���Ԫ��
	����ָ��λ��ɾ��Ԫ��
********************************************/
struct LinkNode
{
	int data;
	LinkNode* pt;
};

class LinkList
{
public:
	LinkList();
	~LinkList();

	void CreateListFront(int n);
	void CreateListTail(int n);
	void ReadWholeList();
	void DelList();
	void SelEle(int n);
	void InsertElem(int n);
	void DeleteElm(int n);

private:
	LinkNode *front;
	int size;
};


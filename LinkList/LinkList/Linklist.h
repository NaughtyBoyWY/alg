#pragma once
#include<iostream>
#include<random>
#include<ctime>
using namespace std;
/********************************************
带头节点的单向链表
成员：
	LinkNode*	front
	int			size
实现功能：
	随机创建一个长度为n的链表（头插法）
	随机创建一个长度为n的链表（尾插法）
	链表整体读取
	链表元素读取
	链表删除
	链表指定位置插入元素
	链表指定位置删除元素
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


#pragma once
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

private:
	LinkNode *front;
	int size;
};

LinkList::LinkList()
{
}

LinkList::~LinkList()
{
}
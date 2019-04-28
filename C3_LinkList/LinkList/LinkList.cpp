#include"Linklist.h"
LinkList::LinkList()
{
	front = new LinkNode;
	front->data = 0;
	front->pt = NULL;
	size = 0;
}

LinkList::~LinkList()
{
	DelList();
	delete front;
}

void LinkList::CreateListFront(int n)
{
	if (n <= 0)
		return;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		LinkNode* p = new LinkNode;
		p->data = rand() % 100;
		p->pt = front->pt;
		front->pt = p;
	}
	size = front->data = n;
}

void LinkList::CreateListTail(int n)
{
	if (n <= 0)
		return;
	srand(time(0));
	LinkNode* r;
	r = front;
	for (int i = 0; i < n; i++)
	{
		LinkNode* p = new LinkNode;
		p->data = rand() % 100;
		p->pt = NULL;
		r->pt = p;
		r = p;
	}
	size = front->data = n;
}
void LinkList::ReadWholeList()
{
	LinkNode* p = front;
	if (size==0)
		return;
	p = p->pt;
	while (p)
	{
		cout << p->data << endl;
		p = p->pt;
	}
}
void LinkList::DelList()
{
	if (size == 0)
		return;
	LinkNode* p = front;
	LinkNode* q;
	p = p->pt;
	while (p)
	{
		q = p->pt;
		delete p;
		p = q;
	}
	front->pt = NULL;
}
void LinkList::SelEle(int n)
{
	if (n > size)
		return;
	LinkNode* p = front;
	int i = 0;
	while (i < n)
	{
		p = p->pt;
		++i;
	}
	cout << (p->data) << endl;
}
void LinkList::InsertElem(int n,int data)
{
	if (n > size+1)
		return;
	LinkNode* p = front;
	int i = 0;
	while (i<n-1)
	{
		p = p->pt;
		++i;
	}
	LinkNode* newNode = new LinkNode;
	newNode->data = data;
	newNode->pt = p->pt;
	p->pt = newNode;
	size = front->data = size + 1;
}
void LinkList::DeleteElm(int n)
{
	if (n > size)
		return;
	LinkNode* p = front;
	int i = 0;
	while (i < n - 1)
	{
		p = p->pt;
		++i;
	}
	p->pt = p->pt->pt;
	size = front->data = size - 1;
}
#include"Linklist.h"
void main()
{
	LinkList listA;
	listA.ReadWholeList();
	listA.CreateListFront(10);
	listA.SelEle(3);
	listA.ReadWholeList();
	cout << endl;

	LinkList listB;
	listB.ReadWholeList();
	listB.CreateListTail(10);
	listB.SelEle(3);
	listB.ReadWholeList();
	cin.get();
}
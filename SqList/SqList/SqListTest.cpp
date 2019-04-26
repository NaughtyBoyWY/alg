#include"SqList.h"

int main()
{
	SqList ListA;
	ListA.PrintList();
	bool Res = ListA.InsertElem(0, 0);
	Res = ListA.InsertElem(1, 1);
	Res = ListA.InsertElem(2, 2);
	Res = ListA.InsertElem(3, 3);
	Res = ListA.InsertElem(4, 4);
	Res = ListA.InsertElem(5, 5);
	Res = ListA.InsertElem(0, 6);
	ListA.DeleteElem(1);
	ListA.PrintList();
	cin.get();
}
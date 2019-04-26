#include"Sort.h"

void Swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
/************************************************************************
Function Name:	QuickSort
Description:	Time Complexity O(nlogn)
Param1:	L
Param2:	low
Param3:	high
Return:	int
*************************************************************************/
int Partition(SqList* L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		Swap(L, low, high);
		while (low < high && L->r[low] <= pivotkey)
			low++;
		Swap(L, low, high);
	}
	return low;
}


void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);
		QSort(L, pivot + 1, high);
	}
}

void main()
{
	SqList SLa = { {80,50,10,90,30,70,40,82,60,20},10 };

	QSort(&SLa, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << SLa.r[i] << endl;
	cin.get();
}

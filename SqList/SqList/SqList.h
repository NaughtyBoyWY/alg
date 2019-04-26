#pragma once
#include<iostream>
using namespace std;
const int MaxSize = 20;
typedef int ElemType;

class SqList
{
private:
	ElemType m_Data[MaxSize];
	int m_nLength;

public:
	SqList();
	SqList(ElemType* Data);
	void EmptyList();
	bool LookForElem(int n, ElemType& data);
	bool ModifyElem(int n, ElemType data);
	int GetListLen();
	bool InsertElem(int n, ElemType data);
	bool DeleteElem(int n);
	void PrintList();
};
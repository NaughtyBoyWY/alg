#include "SqList.h"

SqList::SqList()
{
	for (int i = 0; i < MaxSize; i++)
		m_Data[i] = 0;
	m_nLength = 0;
}


SqList::SqList(ElemType* Data)
{
	for (int i = 0; i < MaxSize; i++)
		m_Data[i] = 0;
	int nLen = sizeof(Data) / sizeof(ElemType);
	if (nLen > MaxSize)
	{
		for (int i = 0; i < MaxSize; i++)
			m_Data[i] = 0;
		m_nLength = 0;
	}
	else
	{
		for (int i = 0; i < nLen; i++)
			m_Data[i] = Data[i];
	}
	m_nLength = nLen;
}

void SqList::EmptyList()
{
	for (int i = 0; i < m_nLength; i++)
		m_Data[i] = 0;
}

bool SqList::LookForElem(int n,ElemType& data)
{
	if (n >= m_nLength || n < 0)
		return false;
	else
		data = m_Data[n];
	return true;
}

bool SqList::ModifyElem(int n,ElemType data)
{
	if (n >= m_nLength || n < 0)
		return false;
	else
		m_Data[n] = data;
	return true;
}

int SqList::GetListLen()
{
	return m_nLength;
}

bool SqList::InsertElem(int n,ElemType data)
{
	if (m_nLength == MaxSize|| n<0 || n > m_nLength)
		return false;
	if (n == m_nLength)
		m_Data[n] = data;
	if (n <= m_nLength)
	{
		for (int i = m_nLength; i > n; i--)
		{
			m_Data[i] = m_Data[i-1];
		}
		m_Data[n] = data;
	}
	m_nLength++;
	return true;
}

bool SqList::DeleteElem(int n)
{
	if (m_nLength == 0|| n<0 || n > m_nLength-1)
		return false;
	if (n < m_nLength || n>=0)
	{
		for (int i = n; i < m_nLength; i++)
			m_Data[i] = m_Data[i + 1];
	}
	m_nLength--;
	return true;
}

void SqList::PrintList()
{
	if (m_nLength == 0)
		cout << "No Elements!"<< endl;
	else
	{
		for (int i = 0; i < m_nLength; i++)
			cout << "第"<<i<<"个："<<m_Data[i] << endl;
		cout << "共" << m_nLength << "个" << endl;
	}
}

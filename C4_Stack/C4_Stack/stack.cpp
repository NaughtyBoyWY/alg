#include"stack.h"

MyStack::MyStack()
{
	for (int i = 0;i < MaxSize; i++)
		m_elem[i] = 0;
	m_size =-1;
}

MyStack::~MyStack()
{
}
bool MyStack::Push(int elem)
{
	if (MaxSize == m_size)
		return false;
	m_elem[++m_size] = elem;
	return true;
}
bool MyStack::Pop()
{
	if (m_size == 0)
		return false;
	m_elem[m_size--] = 0;
	return true;
}
bool MyStack::IsEmpty()
{
	if (m_size == -1)
		return true;
	else
		return false;
}
int MyStack::Size()
{
	return m_size+1;
}
bool MyStack::Top(int& top)
{
	if (m_size == 0)
		return false;
	top = m_elem[m_size];
	return true;
}
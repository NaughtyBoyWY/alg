#include"LinkStack.h"
LinkStack::LinkStack()
{
	m_top = new LinkNode;
	m_top = 0;
	m_size = 0;
}

LinkStack::~LinkStack()
{
	LinkStack::DelStack();
	delete m_top;
}
void LinkStack::Push(int elem)
{
	LinkNode*p = new LinkNode;
	p->data = elem;
	p->pt = m_top;
	m_top = p;
	++m_size;
}
bool LinkStack::Pop()
{
	if (m_size <= 0)
		return false;
	LinkNode* p = m_top;
	m_top = p->pt;
	delete p;
	--m_size;
	return true;
}
int LinkStack::Size()
{
	return m_size;
}
bool LinkStack::DelStack()
{
	if (m_size == 0)
		return false;
	LinkNode* p = m_top;
	while (p)
	{
		m_top = p->pt;
		delete p;
		p = m_top;
	}
	return true;
}
void LinkStack::Show()
{
	LinkNode* p=m_top;
	while (p)
	{
		cout << p->data << endl;
		p = p->pt;
	}
}

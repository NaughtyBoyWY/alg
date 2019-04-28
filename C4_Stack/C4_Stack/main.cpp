#include"stack.h"
int main()
{
	MyStack s1;
	s1.Push(1);
	s1.Push(3);
	s1.Push(5);
	s1.Push(7);
	s1.Push(9);
	cout << s1.Size() << endl;
	int top;
	s1.Top(top);
	cout << top << endl;
	bool res = s1.IsEmpty();
	cout << res << endl;
	cin.get();
	return 0;
}
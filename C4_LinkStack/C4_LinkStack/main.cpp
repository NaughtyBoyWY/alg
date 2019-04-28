#include"LinkStack.h"

int main()
{
	LinkStack ls;
	ls.Push(1);
	ls.Push(2);
	ls.Push(3);
	ls.Push(5);
	ls.Push(6);
	ls.Push(7);
	ls.Push(8);
	ls.Push(9);
	ls.Pop();
	ls.Show();
	cout << ls.Size() << endl;
	cin.get();
	return 0;
}
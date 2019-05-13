#include <iostream>
/***************综述************************
C++容器：
	序列容器：vector list deque queue stack 
	关联容器（键+值）：set map
C++11新增：
	array forward_list 
	unordered_map unordered_set 
***************************************************/

/***************头文件array************************
数组：
	序列容器
	定长
	比[]数组多一些方法，更方便
	存储连续、支持随机访问
***************************************************/
#include<array>
using namespace std;
void ContainArry()
{
	array<int, 10> arrayA{ 0 };
	array<int, 10> arrayB{ 0 };
	//成员函数-元素获取
	for (int i = 0; i < 10; i++)
		arrayA.at(i) = i;
	cout << endl;
	cout << arrayA.front() << endl;
	cout << arrayA.back() << endl;
	cout << endl;
	//成员函数-元素修改
	arrayA.fill(10);
	arrayA.swap(arrayB);
	//成员函数-迭代器
	cout << *arrayA.begin() << endl;
	cout << *(arrayA.end()-1) << endl;
	cout << *arrayA.rbegin() << endl;
	cout << *(arrayA.rend()-1) << endl;
	cout << endl;
	//成员函数-容量
	cout << arrayA.size() << endl;
	cout << arrayA.max_size() << endl;
	cout << arrayA.empty() << endl;
	cout << sizeof(arrayA) << endl;
}
/***************头文件vector************************
矢量：
	序列容器
	动态大小
	存储连续
	在结尾插入和删除元素的时间是固定的
***************************************************/
#include<vector>
void ContainVector()
{
	vector<int> myvector;
	for (int i = 0; i < 100; i++) myvector.push_back(i);
	//成员函数-迭代器
	//成员函数-修改容量：size max_size resize capacity empty reserve shink_to_fit
	myvector.reserve(1000);					//申请空间
	cout << myvector.size() << endl;
	cout << myvector.max_size() << endl;
	cout << myvector.capacity() << endl;
	//成员函数-获取元素 [] at front back data
	//成员函数-修改元素 assign push_back pop_back insert erase swap clear
	//					emplace emplace_back
}

/***************头文件list************************
双向链表：
	序列容器
	存储不连续，获取元素需要遍历
	插入删除时间固定

	成员函数相比vector多一些插入删除和排序功能
	//成员函数-迭代器
	//成员函数-修改容量：size max_size resize empty
	//成员函数-获取元素：front back data
	//成员函数-修改元素：assign push_back pop_back push_front pop_front
	//					emplace emplace_back emplace_front
	//					insert erase swap clear
	//成员函数-操作：splice remove remove_if unique merge sort reverse
***************************************************/
#include<list>
bool is_odd (const int& value) 
{ 
	return (value % 2) == 1; 
}
bool is_near(const int first, const int second)
{
	return (fabs(first - second) <= 2);
}
bool compare_nocase(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i])) return true;
		else if (tolower(first[i]) > tolower(second[i])) return false;
		++i;
	}
	return (first.length() < second.length());
}
bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}
void ContainList()
{
	list<int> mylist1, mylist2;
	list<int>::iterator it;
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30
	it = mylist1.begin();
	++it;                         // points to 2
	//整表拼接
	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4	mylist2 (empty)	"it" still points to 2 (the 5th element)
	//单个元素拼接
	mylist2.splice(mylist2.begin(), mylist1, it);	// mylist1: 1 10 20 30 3 4	mylist2: 2	"it" is now invalid.
	it = mylist1.begin();
	std::advance(it, 3);											// "it" points now to 30
	//范围拼接
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());	// mylist1: 30 3 4 1 10 20
	//删除值为某个数字的元素
	mylist1.remove(30);				//mylist1:3 4 1 10 20
	mylist1.remove_if(is_odd);		//mylist1:4 10 20 
	//函数unique：删除重复的元素
	for (int i = 3; i <= 8; ++i)
		mylist1.push_back(2 * i);	//mylist1:4 10 20 6 8 10 12 14 16
	for (int i = 3; i <= 8; ++i)
		mylist1.push_back(2 * i);	//mylist1:4 10 20 6 8 10 12 14 16 6 8 10 12 14 16
	mylist1.sort();
	mylist1.unique();				//mylist1:4 6 8 10 12 14 16 20
	mylist1.unique(is_near);				//mylist1:4 8 12 16 20
	std::cout << "mylist1 contains:";
	for (it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//函数sort：排序链表
	std::list<std::string> mylist;
	std::list<std::string>::iterator ite;
	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");
	mylist.sort();
	std::cout << "mylist contains:";
	for (ite = mylist.begin(); ite != mylist.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';
	mylist.sort(compare_nocase);
	std::cout << "mylist contains:";
	for (ite = mylist.begin(); ite != mylist.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';
	//函数merge：合并排序好的两个链表
	std::list<double> first, second;
	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);
	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);
	first.sort();
	second.sort();
	first.merge(second);	// (second is now empty)
	
	second.push_back(2.1);
	first.merge(second, mycomparison);
	//函数reverse：反转链表
	first.reverse();
	std::cout << "first contains:";
	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}
/***************头文件deque************************
双向队列：
	序列容器
	动态大小
	存储不连续，但使用map映射支持随机访问，所以插入删除等操作花费时间比vector多
	在开头和结尾插入和删除元素的时间是固定的
***************************************************/
#include<deque>
void ContainDeque()
{
	deque<int> mydeque;
	//成员函数-修改容量，并以某数字填充（默认为0）
	mydeque.resize(5);
	mydeque.resize(10, 100);

	//成员函数-迭代器
	deque<int>::iterator it;			//插入删除都会使迭代器失效
	//成员函数-修改数据
	mydeque.clear();
	mydeque.assign(5, 2);
	mydeque.pop_back();
	mydeque.pop_front();
	mydeque.push_front(3);				//emplace_front就地插入
	mydeque.push_back(1);				//emplace_back就地插入

	it = mydeque.begin();
	it = mydeque.insert(it + 3, 2, 8);	//返回迭代器在插入位置	emplace就地插入
	it = mydeque.erase(it);				//返回迭代器在删除元素后面的位置
	cout << *it << endl;

	deque<int> andeque;
	andeque.assign(10, 3);
	andeque.swap(mydeque);
	andeque.swap(mydeque);
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
		std::cout << *it << ' ';
	cout << endl;
	//成员函数-容量
	cout << mydeque.size() << endl;
	cout << mydeque.max_size() << endl;
}
/***************头文件stack************************
栈：
	后进先出栈
	序列容器
实现：stack是一个容器适配器，底层使用vector、deque或list实例化实现
操作：	empty
		size
		top
		push
		emplace
		pop
		swap
		无迭代器
***************************************************/
#include<stack>
/***************头文件queue************************
队列：
	先进先出队列
	序列容器
实现：queue是一个容器适配器，底层使用deque或list实例化实现
操作：	无迭代器
		构造函数
		empty
		size
		front
		back
		swap
		push
		emplace
		swap
***************************************************/
#include<queue>

/***************头文件set************************
集合：
	关联容器
set：
	性质：
		键值类型相同（键就是值），键是唯一的，键对应的值是唯一的
		set中的值不能修改，只能插入或者删除
		set中元素按一定的顺序排列
		set通过二叉查找树实现
	操作：
		迭代器
		容量：	empty size max_size
		修改：	insert
				erase
				swap
				clear
				emplace
				emplace_hint
		操作：	find
				count
				lower_bound
				upper_bound
				equal_range
multiset：键值类型相同，键是唯一的，键对应的值可以是多个
***************************************************/
#include<set>
void ContainSet()
{
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator, bool> ret;
	// set some initial values:
	for (int i = 1; i <= 5; ++i) myset.insert(i * 10);    // set: 10 20 30 40 50
	ret = myset.insert(20);               // no new element inserted
	if (ret.second == false) it = ret.first;  // "it" now points to element 20
	myset.insert(it, 25);                 // max efficiency inserting
	myset.insert(it, 24);                 // max efficiency inserting
	myset.insert(it, 26);                 // no max efficiency inserting
	int myints[] = { 5,10,15 };              // 10 already in set, not inserted
	myset.insert(myints, myints + 3);

	cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}
/***************头文件map************************
映射：
	关联容器
***************************************************/
#include<map>


//主函数
int main()
{
	ContainSet();

	cin.get();
	return 0;
}
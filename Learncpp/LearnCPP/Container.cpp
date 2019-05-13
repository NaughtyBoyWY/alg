#include <iostream>
/***************����************************
C++������
	����������vector list deque queue stack 
	������������+ֵ����set map
C++11������
	array forward_list 
	unordered_map unordered_set 
***************************************************/

/***************ͷ�ļ�array************************
���飺
	��������
	����
	��[]�����һЩ������������
	�洢������֧���������
***************************************************/
#include<array>
using namespace std;
void ContainArry()
{
	array<int, 10> arrayA{ 0 };
	array<int, 10> arrayB{ 0 };
	//��Ա����-Ԫ�ػ�ȡ
	for (int i = 0; i < 10; i++)
		arrayA.at(i) = i;
	cout << endl;
	cout << arrayA.front() << endl;
	cout << arrayA.back() << endl;
	cout << endl;
	//��Ա����-Ԫ���޸�
	arrayA.fill(10);
	arrayA.swap(arrayB);
	//��Ա����-������
	cout << *arrayA.begin() << endl;
	cout << *(arrayA.end()-1) << endl;
	cout << *arrayA.rbegin() << endl;
	cout << *(arrayA.rend()-1) << endl;
	cout << endl;
	//��Ա����-����
	cout << arrayA.size() << endl;
	cout << arrayA.max_size() << endl;
	cout << arrayA.empty() << endl;
	cout << sizeof(arrayA) << endl;
}
/***************ͷ�ļ�vector************************
ʸ����
	��������
	��̬��С
	�洢����
	�ڽ�β�����ɾ��Ԫ�ص�ʱ���ǹ̶���
***************************************************/
#include<vector>
void ContainVector()
{
	vector<int> myvector;
	for (int i = 0; i < 100; i++) myvector.push_back(i);
	//��Ա����-������
	//��Ա����-�޸�������size max_size resize capacity empty reserve shink_to_fit
	myvector.reserve(1000);					//����ռ�
	cout << myvector.size() << endl;
	cout << myvector.max_size() << endl;
	cout << myvector.capacity() << endl;
	//��Ա����-��ȡԪ�� [] at front back data
	//��Ա����-�޸�Ԫ�� assign push_back pop_back insert erase swap clear
	//					emplace emplace_back
}

/***************ͷ�ļ�list************************
˫������
	��������
	�洢����������ȡԪ����Ҫ����
	����ɾ��ʱ��̶�

	��Ա�������vector��һЩ����ɾ����������
	//��Ա����-������
	//��Ա����-�޸�������size max_size resize empty
	//��Ա����-��ȡԪ�أ�front back data
	//��Ա����-�޸�Ԫ�أ�assign push_back pop_back push_front pop_front
	//					emplace emplace_back emplace_front
	//					insert erase swap clear
	//��Ա����-������splice remove remove_if unique merge sort reverse
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
	//����ƴ��
	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4	mylist2 (empty)	"it" still points to 2 (the 5th element)
	//����Ԫ��ƴ��
	mylist2.splice(mylist2.begin(), mylist1, it);	// mylist1: 1 10 20 30 3 4	mylist2: 2	"it" is now invalid.
	it = mylist1.begin();
	std::advance(it, 3);											// "it" points now to 30
	//��Χƴ��
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());	// mylist1: 30 3 4 1 10 20
	//ɾ��ֵΪĳ�����ֵ�Ԫ��
	mylist1.remove(30);				//mylist1:3 4 1 10 20
	mylist1.remove_if(is_odd);		//mylist1:4 10 20 
	//����unique��ɾ���ظ���Ԫ��
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
	//����sort����������
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
	//����merge���ϲ�����õ���������
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
	//����reverse����ת����
	first.reverse();
	std::cout << "first contains:";
	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}
/***************ͷ�ļ�deque************************
˫����У�
	��������
	��̬��С
	�洢����������ʹ��mapӳ��֧��������ʣ����Բ���ɾ���Ȳ�������ʱ���vector��
	�ڿ�ͷ�ͽ�β�����ɾ��Ԫ�ص�ʱ���ǹ̶���
***************************************************/
#include<deque>
void ContainDeque()
{
	deque<int> mydeque;
	//��Ա����-�޸�����������ĳ������䣨Ĭ��Ϊ0��
	mydeque.resize(5);
	mydeque.resize(10, 100);

	//��Ա����-������
	deque<int>::iterator it;			//����ɾ������ʹ������ʧЧ
	//��Ա����-�޸�����
	mydeque.clear();
	mydeque.assign(5, 2);
	mydeque.pop_back();
	mydeque.pop_front();
	mydeque.push_front(3);				//emplace_front�͵ز���
	mydeque.push_back(1);				//emplace_back�͵ز���

	it = mydeque.begin();
	it = mydeque.insert(it + 3, 2, 8);	//���ص������ڲ���λ��	emplace�͵ز���
	it = mydeque.erase(it);				//���ص�������ɾ��Ԫ�غ����λ��
	cout << *it << endl;

	deque<int> andeque;
	andeque.assign(10, 3);
	andeque.swap(mydeque);
	andeque.swap(mydeque);
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
		std::cout << *it << ' ';
	cout << endl;
	//��Ա����-����
	cout << mydeque.size() << endl;
	cout << mydeque.max_size() << endl;
}
/***************ͷ�ļ�stack************************
ջ��
	����ȳ�ջ
	��������
ʵ�֣�stack��һ���������������ײ�ʹ��vector��deque��listʵ����ʵ��
������	empty
		size
		top
		push
		emplace
		pop
		swap
		�޵�����
***************************************************/
#include<stack>
/***************ͷ�ļ�queue************************
���У�
	�Ƚ��ȳ�����
	��������
ʵ�֣�queue��һ���������������ײ�ʹ��deque��listʵ����ʵ��
������	�޵�����
		���캯��
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

/***************ͷ�ļ�set************************
���ϣ�
	��������
set��
	���ʣ�
		��ֵ������ͬ��������ֵ��������Ψһ�ģ�����Ӧ��ֵ��Ψһ��
		set�е�ֵ�����޸ģ�ֻ�ܲ������ɾ��
		set��Ԫ�ذ�һ����˳������
		setͨ�����������ʵ��
	������
		������
		������	empty size max_size
		�޸ģ�	insert
				erase
				swap
				clear
				emplace
				emplace_hint
		������	find
				count
				lower_bound
				upper_bound
				equal_range
multiset����ֵ������ͬ������Ψһ�ģ�����Ӧ��ֵ�����Ƕ��
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
/***************ͷ�ļ�map************************
ӳ�䣺
	��������
***************************************************/
#include<map>


//������
int main()
{
	ContainSet();

	cin.get();
	return 0;
}
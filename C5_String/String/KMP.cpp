/*locate substring by KMP(Knuth Morris Pratt)*/
#include<string>
#include<cstring>
#include<iostream>

using namespace std;
void GetNext(string str, int *next);
void GetNextVal(string str, int *nextval);

int IndexKMP(string s, string t, int pos);
void main()
{
	string strA = "ababaaaba";
	string strB = "ab";
	
	int l = IndexKMP(strA, strB, 0);
	int m = IndexKMP(strA, strB, 1);
	int n = IndexKMP(strA, strB, 2);
	int x = IndexKMP(strA, strB, 3);
	printf("%d\n%d\n%d\n%d\n", l, m, n, x);
	system("pause");
}

void GetNext(string str, int *next)
{
	int i, j;
	next[0] = 0;
	i = 1;
	j = 0;
	while (i <str.length())
	{
		if (j == 0 || str[j-1] == str[i-1])
		{
			++i;
			++j;
			next[i-1] = j ;
		}
		else
			j = next[j-1];
	}
}
//advanced alg
void GetNextVal(string str, int *nextval)
{
	int i, j;
	nextval[0] = 0;
	i = 1;
	j = 0;
	while (i < str.length())
	{
		if (j == 0 || str[j - 1] == str[i - 1])
		{
			++i;
			++j;
			if(str[j - 1] == str[i - 1])
				nextval[i - 1] = j;
			else
				nextval[i - 1] = nextval[j - 1];
		}
		else
			j = nextval[j - 1];
	}
}

int IndexKMP(string s, string t, int pos)
{
	int i = pos;
	int j = 0;
	int next[255];
	GetNextVal(t, next);
	while (i <= s.length() && j <= t.length())
	{
		if (j == 0 || s[i-1] == t[j-1])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j-1];
		}
	}
	if (j > t.length())
		return i - t.length() -1;
	else
		return 0;
}
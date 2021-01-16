#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int NR = 1000 + 5;
char s[NR], c[NR]; 
namespace Recurring 
{
	void decimal()
	{
		
	}
}
int main()
{
	for (int i = 1; i >= 0; i++)
	{
		cin >> s[i];
		if (s[i] == '.')
			break;
	}
	cin >> c + 1;
	int len_c = strlen(c + 1), len_s = strlen(s + 1) - 1;
	for (int i = 1; i <= len_c; i++)
	{
		if (c[i] == '(')
		{
			Recurring::decimal();
			return 0;
		}
	}
	normal::decimal();
	return 0;
}


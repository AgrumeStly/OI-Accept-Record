#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, maxx = -1e9, minn = 1e9; 
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (maxx < a) maxx = a;
		if (minn > a) minn = a;
	}
	cout << maxx - minn << endl;
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
int a[1005][1005];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++)
			for (int k = y1; k <= y2; k++)
				a[j][k]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		puts("");
	}
	return 0;
}


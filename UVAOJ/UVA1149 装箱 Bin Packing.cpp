#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int NR = 1e5 + 5;
int t, n, m, v[NR], front, after, ans;
void Initialization()
{
	memset(v, 0, sizeof(v));
	n = 0;
	m = 0;
	front = 1;
	after = 0;
	ans = 0;
}
void Cin()
{
	cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
	after = n;
}
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	cin >> t;
	Initialization();
	for (int T = 1; T <= t; T++)
	{
		Cin();
		sort(v + 1, v + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			if (front >= after)
			{
				ans++;
				cout << ans << endl;
				Initialization();
				break;
			}
			else if (v[front] + v[after] <= m)
			{
				ans++;
				front++;
				after--;
			}
			else
			{
				ans++;
				front++;
			}
	}
	return 0;
}


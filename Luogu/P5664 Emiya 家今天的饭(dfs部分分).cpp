/*
  Problem:P5664 
  Date:07/06/20 09:24
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 105, MR = 2005, MOD = 998244353;
int n, m, a[NR][MR], num[MR], ans;
void dfs (int k, long long sum, int x, int y) {
	if (y == x) {
		ans = (ans + sum) % MOD;
		return;
	}
	if (k > n) return;
	for (int i = 1; i <= m; i++)
		if (num[i] + 1 <= x / 2) {
			num[i]++;
			dfs(k + 1, sum * a[k][i] % MOD, x, y + 1);
			num[i]--;
		}
	dfs (k + 1, sum, x, y);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 2; i <= n; i++)
		dfs (1, 1, i, 0);
	cout << ans << endl;
	return 0;
}


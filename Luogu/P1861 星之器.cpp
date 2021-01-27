/*
  Problem:P1861
  Date:17/06/20 16:31
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long
using namespace std;
const int NR = 205;
int n, m, a[NR][NR], num, ans;
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num;
			ans += (a[i][j] - num) * (i * i + j * j);
		}
	}
	cout << ans / 2 << endl;
	return 0;
}


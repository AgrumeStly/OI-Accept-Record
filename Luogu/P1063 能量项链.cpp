/*
  Problem:P1063
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 205;
int n, a[NR], dp[NR][NR], ans;

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j + i - 1 <= 2 * n; j++) {
			int tmp = j + i - 1;
			for (int k = j; k <= tmp - 1; k++) {
				dp[j][tmp] = max (dp[j][tmp], dp[j][k] + dp[k + 1][tmp] + a[j] * a[k + 1] * a[tmp + 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max (ans, dp[i][i + n - 1]);
	}
	cout << ans << endl;
	return 0;
}


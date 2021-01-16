/*
  Problem:P1880
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
int n, a[NR], s[NR], dp[NR][NR], min_ans = 2e9, max_ans = 0;

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	memset (dp, 0x3f, sizeof dp);
	for (int i = 1; i <= 2 * n; i++) {
		dp[i][i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j + i - 1 <= 2 * n; j++) {
			int tmp = j + i - 1;
			for (int k = j; k <= tmp - 1; k++) {
				dp[j][tmp] = min (dp[j][tmp], dp[j][k] + dp[k + 1][tmp] + s[tmp] - s[j - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		min_ans = min (min_ans, dp[i][i + n - 1]);
	}
	memset (dp, 0, sizeof dp);
	for (int i = 1; i <= 2 * n; i++) {
		dp[i][i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j + i - 1 <= 2 * n; j++) {
			int tmp = j + i - 1;
			for (int k = j; k <= tmp - 1; k++) {
				dp[j][tmp] = max (dp[j][tmp], dp[j][k] + dp[k + 1][tmp] + s[tmp] - s[j - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		max_ans = max (max_ans, dp[i][i + n - 1]);
	}
	cout << min_ans << endl << max_ans << endl;
	return 0;
}


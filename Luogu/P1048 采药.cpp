/*
  Problem:P1048
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 105;
int t, m, w[NR], v[NR], dp[1005];

int main () {
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= 0; j--) {
			if (j >= w[i]) {
				dp[j] = max (dp[j - w[i]] + v[i], dp[j]);
			}
		}
	}
	cout << dp[t] << endl;
	return 0;
}

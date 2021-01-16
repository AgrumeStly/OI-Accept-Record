#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 105, MOD = 1000007;
int n, m;
int a[NR];
int f[NR][NR];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= min(j, a[i]); k++) {
				f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}


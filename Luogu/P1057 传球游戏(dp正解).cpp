#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int f[35][35];
int n, m;
int main() {
	cin >> n >> m;
	f[1][n] = f[1][2] = 1;
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = f[i - 1][(j - 1 + n - 1) % n + 1] + f[i - 1][(j + 1 + n - 1) % n + 1];
		}
	}
	cout << f[m][1] << endl;
	return 0;
}


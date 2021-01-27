#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 1005;
const int MR = 100005;
int n, m;
int mapp[NR][NR];
int x[MR], y[MR];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '1') mapp[i][j] = 1;
			else mapp[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		dfs(x[i], y[i], )
	}
	return 0;
}


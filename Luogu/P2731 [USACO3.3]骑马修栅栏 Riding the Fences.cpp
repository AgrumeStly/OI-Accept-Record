#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int NR = 1500;
int m, cnt, u, v, n;
int g[NR][NR], d[NR];
int p[NR];

void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (g[x][i]) {
			g[x][i]--;
			g[i][x]--;
			dfs(i);
		}
	}
	p[++cnt] = x;
}

int main() {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		g[u][v]++;
		g[v][u]++;
		n = max(n, max(u, v));
		d[u]++; d[v]++;
	}
	int s = 1;
	for (int i = 1; i <= n; i++)
		if (d[i] % 2 == 1) {
			s = i;
			break;
		}
	dfs(s);
	for (int i = cnt; i >= 1; i--) {
		cout << p[i] << endl;
	}
	return 0;
}


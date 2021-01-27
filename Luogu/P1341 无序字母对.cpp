#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int NR = 350;
int n, u, v, cnt, scnt, st;
int g[NR][NR], d[NR];
char s[2], p[NR * 10];

void dfs(int x) {
	for (int i = 1; i <= 130; i++)
		if (g[x][i]) {
			g[x][i]--;
			g[i][x]--;
			dfs(i);
		}
	p[++cnt] = x;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		u = s[0], v = s[1];
		g[u][v]++, g[v][u]++;
		d[u]++, d[v]++;
	}
	for (int i = 1; i <= 130; i++)
		if (d[i] % 2 == 1) {
			scnt++;
			if (st == 0)
				st = i;
		}
	if (st == 0)
		for (int i = 1; i <= 130; i++)
			if (d[i]) {
				st = i;
				break;
			}
	if (scnt != 2 && scnt != 0) {
		cout << "No Solution\n";
		return 0;
	}
	dfs(st);
	if (scnt == n + 1) {
		cout << "No Solution\n";
		return 0;
	}
	for (int i = n + 1; i >= 1; i--) {
		cout << p[i];
	}
	puts("");
	return 0;
}


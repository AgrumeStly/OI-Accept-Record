#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define ll long long
using namespace std;

inline int read() {
	int f = 1, x = 0; char ch;
	do {
		ch = getchar();
		if (ch == '-') f = -1;
	} while (ch < '0' || ch > '9');
	do {
		x = x * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return f * x;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar (x % 10 + '0');
}

const int NR = 705;
int n, m;
struct node {
	int h, ax, ay;
} a[NR * NR];
int b[NR][NR];
bool f[NR][NR];
int lena, ans;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

bool cmp(node x, node y) {
	return x.h > y.h; 
}

void dfs(int x, int y) {
	if (x > n || y > m || x < 1 || y < 1) return;
	f[x][y] = 1;
	for (int i = 0; i < 8; i++)
		if (!f[x + dx[i]][y + dy[i]] && b[x + dx[i]][y + dy[i]] <= b[x][y])
			dfs(x + dx[i], y + dy[i]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
			a[++lena].h = b[i][j];
			a[lena].ax = i;
			a[lena].ay = j;
		}
	sort(a + 1, a + lena + 1, cmp);
	for (int i = 1; i <= lena; i++) {
		int x = a[i].ax, y = a[i].ay;
		if (!f[x][y]) {
			bool ff = 1;
			for (int j = 0; j < 8; j++)
				if (b[x][y] < b[x + dx[j]][y + dy[j]]) ff = 0;
			if(ff) {
				dfs(x, y);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}


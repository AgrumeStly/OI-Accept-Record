#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int NR = 1005;
int n, h, r, g[NR][NR];
bool vis[1005], flag;

struct point {
	double x, y, z;
} p[NR];

double sqr(double a) {
	return a * a;
}

double dist(point a, point b) {
	sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}

void dfs(int x) {
	if (vis[x]) return;
	if (p[x].z + r >= n) {
		flag = true;
		return;
	}
	vis[x] = true;
	for (int i = 1; i <= n; i++)
		if (g[x][i] && !vis[i])
			dfs(i);
}

void solve() {
	flag = false;
	memset(vis, false, sizeof vis);
	memset(g, 0, sizeof g);
	cin >> n >> h >> r;
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dist(p[i], p[j]) <= 2 * r) {
				g[i][j] = 1;
				g[j][i] = 1;
			}
	for (int i = 1; i <= n; i++)
		if (p[i].z <= r)
			dfs(i);
	if (flag) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}


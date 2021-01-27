#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 505;
int m, n;
int oilmap[NR][NR];
int ans;
void dfs(int x, int y) {
	if (!x || !y || x > n || y > m) return;
	oilmap[x][y] = 0;
	if (oilmap[x + 1][y + 1]) dfs(x + 1, y + 1);
	if (oilmap[x - 1][y - 1]) dfs(x - 1, y - 1);
	if (oilmap[x + 1][y - 1]) dfs(x + 1, y - 1);
	if (oilmap[x - 1][y + 1]) dfs(x - 1, y + 1);
	if (oilmap[x][y + 1]) dfs(x, y + 1);
	if (oilmap[x + 1][y]) dfs(x + 1, y);
	if (oilmap[x][y - 1]) dfs(x, y - 1);
	if (oilmap[x - 1][y]) dfs(x - 1, y);
	return;
}
int main() {
	cin >> n >> m;
	while (m != 0 && n != 0) {
		memset(oilmap, 0, sizeof(oilmap));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				if (c == '@') oilmap[i][j] = 1;
				else oilmap[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (oilmap[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
		cin >> n >> m;
		memset(oilmap, 0, sizeof(oilmap));
		ans = 0;
	}
	return 0;
}


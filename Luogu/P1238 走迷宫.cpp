#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
#define outxy(X, Y) cout << "(" << X << "," << Y << ")";
#define _to cout << "->";
using namespace std;
const int NR = 20;
int n, m;
int mapp[NR][NR];
int ans[50005][5];
int ax, ay, bx, by;
int a[5][5] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int flag;
int num;//²½Êý
bool tmp[NR][NR];
void print() {
	if (flag == 0) {
		flag = 1;
	}
	for (int i = 0; i < num; i++) {
		outxy(ans[i][0], ans[i][1]);
		_to;
	}
	outxy(bx, by);
	line;
	return;
}
void dfs(int x, int y) {
	if (x == bx && y == by) {
		print();
		return;
	}
	for (int i = 0; i <= 3; i++) {
		if (mapp[x + a[i][0]][y + a[i][1]] && !tmp[x + a[i][0]][y + a[i][1]]) {
			tmp[x][y] = true;
			ans[num][0] = x;
			ans[num][1] = y;
			num++;
			dfs(x + a[i][0], y + a[i][1]);
			num--;
			tmp[x][y] = false;
		}
	}
	return;
}
int main() {
//	freopen("P1238.in", "r", stdin);
//	freopen("P1238.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mapp[i][j];
		}
	}
	cin >> ax >> ay >> bx >> by;
	dfs(ax, ay);
	if (!flag) cout << "-1" << endl;
	return 0;
}


/*
  Problem:UVA10116
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int a[13][13];
char mapp[11][11];
int m, n;
int main() {
	while (cin >> n >> m) {
		if (m == 0 && n == 0)
			break;
		memset (a, 0, sizeof(a));
		for (int i = 0; i < m + 2; i++) {
			a[0][i] = 1;
			a[m + 1][i] = 1;
		}
		for (int i = 0; i < n + 2; i++) {
			a[i][0] = 1;
			a[i][n + 1] = 1;
		}
		int x = 1, y = 1;
		cin >> x;
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= m; i++) {
				cin >> mapp[i][j];
			}
		}
		int xx = x, yy = y;
		while (!a[xx][yy]) {
			a[xx][yy] = 1 + a[x][y];
			x = xx;
			y = yy;
			switch (mapp[xx][yy]) {
				case 'N':
					yy--;
					break;
				case 'S':
					yy++;
					break;
				case 'W':
					xx--;
					break;
				case 'E':
					xx++;
					break;
			}
		}
		if (xx <= 0 || xx > m || yy <= 0 || yy > n) {
			cout << a[x][y] << " step(s) to exit" << endl;
		}
		else {
			int s = a[x][y] - (a[x][y] - a[xx][yy] + 1);
			cout << s << " step(s) before a loop of " << a[x][y] - a[xx][yy] + 1 << " step(s)" << endl;
		}
	}
	return 0;
}

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

const int NR = 105;
int n;
int a[NR][NR], ans;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read();
		a[x][y] += 1;
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 1;  j <= 100; j++)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			for (int k = 1; k <= 100; k++)
				for (int l = 1; l <= 100; l++) {
					int x = a[k][l] - a[k][j - 1] - a[i - 1][l] + a[i - 1][j - 1];
					int y = a[k - 1][l - 1] - a[k - 1][j] - a[i][l - 1] + a[i][j];
					if (ans < x - y) ans = x - y;
				}
	cout << ans << endl;
	return 0;
}

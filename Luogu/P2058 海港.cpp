#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <windows.h>
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

const int NR = 1e6 + 5;
struct node {
	int t, k;
} q[NR];
int n, x, tot, ans, h;
int f[NR];

int main() {
	system("color 07");
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int ti = read(), ki = read();
		for (int j = 1; j <= ki; j++) {
			x = read();
			q[++tot].t = ti;
			q[tot].k = x;
			if (!f[x]) ans++;
			f[x]++;
		}
		while (ti - q[h].t >= 86400) {
			x = q[h].k;
			f[x]--;
			if (!f[x]) {
				ans--;
			}
			h++;
		}
		write(x);
	}
	return 0;
}


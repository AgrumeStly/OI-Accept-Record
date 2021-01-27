#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define ll long long
using namespace std;

const int NR = 3e6 + 6;
int a[NR], n, p;

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

inline void write(int x){
    if (x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar (x % 10 + '0');
}

signed main() {
	n = read(), p = read();
	a[1] = 1;
	puts("1");
	for (int i = 2; i <= n; i++) {
		a[i] = (ll)(p - p / i) * a[p % i] % p;
		write(a[i]);
		puts("");
    }
}

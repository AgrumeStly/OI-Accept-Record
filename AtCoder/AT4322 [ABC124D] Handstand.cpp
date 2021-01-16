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

int n, k;
string s;

int main() {
	n = read(), k = read();
	cin >> s;
	int l = s.size();
	for (int i = 1; i <= l; i++) {
		
	}
	return 0;
}


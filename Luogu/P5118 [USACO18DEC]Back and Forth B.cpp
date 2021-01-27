#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
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

int a[15], b[15], ans;
map<int, bool> mp;

int main() {
	for (int i = 1; i <= 10; i++)
		a[i] = read();
	for (int i = 1; i <= 10; i++)
		b[i] = read();
	mp[1000] = true;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			mp[1000 + b[i] - a[j]] = true;
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			for (int k = i + 1; k <= 10; k++)
				for (int l = j + 1; l <= 10; l++)
					mp[1000 + b[i] - a[j] + b[k] - a[l]] = true;
	for (int i = 1; i <= 1919; i++)
		if (mp[i]) ans++;
	write(ans);
	return 0;
}


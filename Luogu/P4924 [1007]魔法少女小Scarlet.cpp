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

const int NR = 510;
int n, m;
int a[NR][NR], b[NR][NR];

int main() {
	n = read(), m = read();
	int num = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = ++num;
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read(), r = read(), z = read();
		if (z == 0) {
			for (int i = x - r; i <= x + r; i++)
				for (int j = y - r; j <= y + r; j++)
					b[x - y + j][x + y - i] = a[i][j];
			for (int i = x - r; i <= x + r; i++)
				for (int j = y - r; j <= y + r; j++)
					a[i][j] = b[i][j];
		}
		else {
			for (int i = x - r; i <= x + r; i++)
				for (int j = y - r; j <= y + r; j++)
					b[x + y - j][y - x + i] = a[i][j];
			for (int i = x - r; i <= x + r; i++)
				for (int j = y - r; j <= y + r; j++)
					a[i][j] = b[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		puts("");
	}
	return 0;
}

/*
    1  2  3  4  5
   
1   1  2  3  4  5
2   6  7  8  9  10
3   11 12 13 14 15
4   16 17 18 19 20
5   21 22 23 24 25

    1  2  3  4  5
   
1   6  1  2  4  5
2   11 7  3  9  10
3   12 13 8  14 15
4   16 17 18 19 20
5   21 22 23 24 25

    1  2  3  4  5
   
1   6  1  2  4  5
2   11 3  9  14 10
3   12 7  8  19 15
4   16 13 17 18 20
5   21 22 23 24 25
 
    1  2  3  4  5
   
1   6  1  2  4  5
2   11 3  9  14 10
3   12 7  8  19 15
4   16 13 17 18 20
5   21 22 23 24 25

2 2 1 0
3 3 1 1
4 4 1 0
3 3 2 1

    1  2  3
    
1   1  2  3
2   4  5  6
3   7  8  9

2 2 1 0
2 2 1 1
2 2 2 0
3 3 2 0
1 3 2 0
*/

/*
  Problem:P1140
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 105;
const int A = 1;
const int C = 2;
const int G = 3;
const int T = 4;
int lena, lenb;
int a[NR], b[NR], f[NR][NR];
int m[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 5, -1, -2, -1, -3},
	{0, -1, 5, -3, -2, -4},
	{0, -2, -3, 5, -2, -2},
	{0, -1, -2, -2, 5, -1},
	{0, -3, -4, -2, -1, 0},
};

int main () {
	cin >> lena;
	for (int i = 1; i <= lena; i++) {
		char c;
		cin >> c;
		if (c == 'A') a[i] = A;
		if (c == 'C') a[i] = C;
		if (c == 'G') a[i] = G;
		if (c == 'T') a[i] = T;
	}
	cin >> lenb;
	for (int i = 1; i <= lenb; i++) {
		char c;
		cin >> c;
		if (c == 'A') b[i] = A;
		if (c == 'C') b[i] = C;
		if (c == 'G') b[i] = G;
		if (c == 'T') b[i] = T;
	}
	for (int i = 1; i <= lena; i++) {
		f[i][0] = f[i - 1][0] + m[a[i]][5];
	}
	for (int i = 1; i <= lenb; i++) {
		f[0][i] = f[0][i - 1] + m[5][b[i]];
	}
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			f[i][j] = max (f[i - 1][j - 1] + m[a[i]][b[j]], max (f[i - 1][j] + m[a[i]][5], f[i][j - 1] + m[5][b[j]]));
		}
	}
	cout << f[lena][lenb] << endl;
	return 0;
}


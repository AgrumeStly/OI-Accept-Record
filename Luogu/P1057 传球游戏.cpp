/*
  Problem:P1057
  Date:07/06/20 09:50
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 35;
int n, m;
int a[NR][NR];
int dfs (int x, int step) {
	if (x == 0) x = n;
	if (x == n + 1) x = 1;
	if (a[x][step] != 0) return a[x][step];
	if (step == m) {
		if (x == 1) return 1;
	    return 0;
	}
	return a[x][step] = dfs(x + 1, step + 1) + dfs(x - 1, step + 1);
}
int main() {
	cin >> n >> m;
	if (n % 2 == 0 && m % 2 == 1) {
		cout << 0;
		return 0;
	}
	cout << dfs (1, 0);
	return 0;
}


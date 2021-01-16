/*
  Problem:hdu1205
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e6 + 6;
int t;
int n, m[NR];
int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		int maxx = 0;
		long long num = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
			num += m[i];
			maxx = max (maxx, m[i]);
		}
		num -= maxx;
		if (num < maxx - 1) {
			cout << "No" << endl;
		}
		else cout << "Yes" << endl;
	}
	return 0;
}


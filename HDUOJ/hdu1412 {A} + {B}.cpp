/*
  Problem:hdu1412
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#define line cout << endl
using namespace std;
const int NR = 10005;
map <int, bool> mp;
int main () {
	int n, m;
	while (cin >> n >> m) {
		int a;
		int maxx = 0;
		for (int i = 1; i <= n + m; i++) {
			cin >> a;
			mp[a] = true;
			if (maxx < a) maxx = a;
		}
		for (int i = 1; i <= maxx; i++)
			if (mp[i]) cout << i << " ";
		line;
	}
	return 0;
}


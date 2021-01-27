/*
  Problem:SP1167
  Date:23/06/20 08:45
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long
using namespace std;
int n, h;
signed main () {
	cin >> n;
	while (n--) {
		cin >> h;
		cout << (h * h + h) / 6;
		line;
	}
	return 0;
}


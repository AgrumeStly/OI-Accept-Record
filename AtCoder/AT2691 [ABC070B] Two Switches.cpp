/*
  Problem:AT2691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

int a, b, c, d;

int main () {
	cin >> a >> b >> c >> d;
	if (b < c || d < a) {
		cout << "0" << endl;
		return 0;
	}
	int ans = abs (b - a) + abs (d - c);
	ans -= abs (c - a);
	ans -= abs (b - d);
	ans /= 2;
	cout << ans << endl;
	return 0;
}


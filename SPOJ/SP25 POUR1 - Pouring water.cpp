/*
  Problem:SP25
  Date:08/06/20 21:27
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define debug cout << 1
using namespace std;
int a, b, c, T, ans;
int gcd (int x, int y) {return y == 0 ? x : gcd (y, x % y);}
int main () {
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		if (c % gcd (a, b) || c > max (a, b)) {
			cout << "-1";
			line;
			continue;
		}
		int _a = a, _b = b;
		while (_a != c && _b != c) {
			if (_b > _a) {
				swap (_a, _b);
			}
			_a -= _b;
			ans++;
		}
		cout << ans + 1;
		line;
		ans = 0;
		debug;
	}
	return 0;
}


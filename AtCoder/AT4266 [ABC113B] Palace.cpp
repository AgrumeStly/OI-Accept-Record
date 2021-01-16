#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iomanip>
#define line cout << endl
using namespace std;

int n, t, a, num;
double ans = 1e9;

int main() {
	cin >> n;
	cin >> t >> a;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		double _t = t - h * 0.006;
		if (ans > abs(_t - a)) {
			ans = abs(_t - a);
			num = i;
		}
	}
	cout << num << endl;
	return 0;
}


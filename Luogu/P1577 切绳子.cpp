#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
#define int long long
using namespace std;

const int NR = 100005;
int n, k, ans = 1;
int l[NR];
int low = 1, high;

bool check (int x) {
	int num = 0;
	for (int i = 1; i <= n; i++) {
		num += l[i] / x;
	}
	return num >= k;
}

signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		double t;
		cin >> t;
		l[i] = t * 100;
		high = max (high, l[i]);
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check (mid)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	printf ("%.2lf\n", ans / 100.);
	return 0;
}


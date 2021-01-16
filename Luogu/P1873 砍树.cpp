#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
#define int long long
using namespace std;

const int NR = 1000005;
int n, m, ans = 0;
int low, high;
int l[NR];

bool check (int x) {
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (l[i] > x) num += l[i] - x;
	}
	return num >= m;
}

signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
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
	cout << ans << endl;
	return 0;
}


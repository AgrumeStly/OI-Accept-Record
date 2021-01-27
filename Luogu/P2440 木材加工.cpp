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
int n, k, ans, maxn = 1e9;
int l[NR];

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
		cin >> l[i];
		maxn = max (l[i], maxn);
	}
	int low = 1, high = maxn;
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


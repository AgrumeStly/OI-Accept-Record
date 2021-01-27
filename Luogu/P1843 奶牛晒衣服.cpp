#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

const int NR = 5e5 + 5;
int n, a, b, ans, low, high;
int w[NR];

bool check (int x) {
	int num = 0, t;
	for (int i = 1; i <= n; i++) {
		t = w[i] - a * x;
		if (t <= 0) continue;
		num += (t + b - 1) / b;
	}
	return num <= x;
}

int main () {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		high = max(high, w[i]);
	}
//	sort (w + 1, w + n + 1, greater<int>());
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check (mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ans << endl;
	return 0;
}


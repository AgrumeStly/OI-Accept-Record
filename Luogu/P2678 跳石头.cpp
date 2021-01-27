#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

const int NR = 50005;
int n, m, l, ans;
int a[NR];

bool check (int x) {
	int num = 0, t = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - t < x) {
			num++;
		}
		else {
			t = a[i];
		}
	}
	return num <= m;
}

int main () {
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	n++;
	a[n] = l;
	int low, high = l;
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


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

const int NR = 1005;

struct node {
	int t, s;
};

node a[NR];
int n, ans = -1;

bool cmp (node x, node y) {
	return x.s < y.s;
}

bool check (int x) {
	int num = x;
	for (int i = 1; i <= n; i++) {
		if (num + a[i].t <= a[i].s) {
			num += a[i].t;
		}
		else return false;
	}
	return true;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t >> a[i].s;
	}
	sort (a + 1, a + n + 1, cmp);
	int low = 1, high = a[n].s;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans << endl;
	return 0;
}


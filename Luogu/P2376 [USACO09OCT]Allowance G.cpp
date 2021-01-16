/*
  Problem:P2376
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 25;
struct node {
	int v, b;
};
int n, c, ans, b[NR];
node a[NR];

bool cmp (node x, node y) {
	return x.v < y.v;
}

int main () {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].v >> a[i].b;
	}
	sort (a + 1, a + 1 + n, cmp);
	int cnt;
	for (int i = n; i >= 1; i--) {
        if (a[i].v >= c) ans += a[i].b;
        else {
			cnt = i;
			break;
		}
	}
	while (1) {
		int num = c;
		for (int i = cnt; i >= 1; i--) {
			int tmp = min (a[i].b, num / a[i].v);
			num -= tmp * a[i].v;
			b[i] = tmp;
		}
		if (num > 0) {
			for (int i = 1; i <= cnt && num > 0; i++) {
				if (a[i].b > b[i]) {
					num -= a[i].v;
					b[i]++;
				}
			}
		}
		if (num <= 0) {
			int tmp = 2e9;
			for (int i = 1; i <= cnt; i++) {
				if (b[i]) tmp = min (tmp, a[i].b / b[i]);
			}
			ans += tmp;
			for (int i = 1; i <= cnt; i++) {
				a[i].b -= tmp * b[i];
			}
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}


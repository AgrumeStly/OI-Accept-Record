/*
  Problem:P1233
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 1e5 + 5;
struct Wood {
	int l, w;
};
Wood wood[NR];
int n, cnt, f[NR];

bool cmp (Wood x, Wood y) {
	if (x.l == y.l) return x.w < y.w;
	return x.l < y.l;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wood[i].l >> wood[i].w;
	}
	sort (wood + 1, wood + n + 1, cmp);
	int ans = 0;
	while (cnt < n) {
		ans++;
		int l = -1, w = -1;
		for (int i = 1; i <= n; i++) {
			if (!f[i] && wood[i].l >= l && wood[i].w >= w) {
				cnt++;
				f[i] = 1;
				l = wood[i].l;
				w = wood[i].w;
			}
		}
	}
	cout << ans << endl;
	return 0;
}


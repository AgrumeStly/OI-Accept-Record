/*
  Problem:P1208
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 2e6 + 6;
struct Milk {
	int p, a;
};
int n, m, ans;
Milk milk[NR];
bool cmp (Milk x, Milk y) {
	if (x.p == y.p) return x.a > y.a;
	return x.p < y.p;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> milk[i].p >> milk[i].a;
	}
	sort (milk + 1, milk + m + 1, cmp);
	int cnt = 1;
	while (n - milk[cnt].a) {
		n -= milk[cnt].a;
		ans += milk[cnt].p * milk[cnt++].a;
	}
	ans += milk[cnt].p * n;
	cout << ans << endl;
	return 0;
}


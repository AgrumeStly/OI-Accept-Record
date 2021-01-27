/*
  Problem:P1309
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 2e5 + 5;
struct P {
	int s, num;
};
P a[NR], b[NR], s[NR];
int n, r, q, w[NR];
bool cmp (P x, P y) {
	if (x.s == y.s)
		return x.num < y.num;
	return x.s > y.s;
}
void F () {
	int cnti = 1, cntj = 1, cntk = 1;
	while (cnti < n && cntj < n) {
		if (a[cnti].s < b[cntj].s) {
			s[cntk].num = a[cnti].num;
			s[cntk++] = a[cnti++];
		}
		else {
			s[cntk].num = b[cntj].num;
			s[cntk++].s = b[cntj++].s;
		}
	}
	while (cnti <= n) {
		s[cntk].num = a[cnti].num;
		s[cntk++] = a[cnti++];
	}
	while (cntj <= n) {
		s[cntk].num = b[cntj].num;
		s[cntk++] = b[cntj++];
	}
	return;
}
int main () {
	cin >> n >> r >> q;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> s[i].s;
		s[i].num = i;
	}
	for (int i = 1; i <= 2 * n; i++) {
		cin >> w[i];
	}
	sort (a + 1, s + 2 * n + 1, cmp);
	for (int i = 1; i <= r; i++) {
		int cnt = 1;
		for (int j = 1; j < 2 * n; j += 2) {
			if (w[s[j].num] > w[s[j + 1].num]) {
				a[cnt] = b[n];
			}
			else {
				a[cnt].s = s[j + 1].s + 1;
				a[cnt].num = s[j + 1].num;
				b[cnt].s  =  s[j].s;
				b[cnt++].num = s[j].num;
			}
		}
		F ();
	}
	cout << s[q].num << endl;
	return 0;
}


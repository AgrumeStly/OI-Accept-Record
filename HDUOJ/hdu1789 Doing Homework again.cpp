/*
  Problem:hdu1789
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1005;
struct Hw {
	int a, b;
};
Hw hw[NR];
int t;
int n, ans;
bool f[NR];
bool cmp (Hw x, Hw y) {
	return x.b > y.b;
}
int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> hw[i].a;
		for (int i = 1; i <= n; i++)
			cin >> hw[i].b;
		sort (hw + 1, hw + n + 1, cmp);
		bool ff = true;
		for (int i = 1; i <= n; i++) {
			ff = true;
			for (int j = hw[i].a; j >= 1; j--) {
				if (!f[j]) {
					f[j] = true;
					ff = false;
					break;
				}
			}
			if (ff) {
				ans += hw[i].b;
			}
		}
		cout << ans << endl;
		ans = 0;
		memset (f, false, sizeof f);
	}
	return 0;
}


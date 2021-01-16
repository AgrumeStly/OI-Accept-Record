/*
  Problem:hdu3177
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
struct EQ {
	int a, b;
};
int t;
int n, ans, v;
EQ eq[NR];
bool cmp (EQ x, EQ y) {
	return x.b - x.a > y.b - y.a;
} 
int main () {
	cin >> t;
	while (t--) {
		cin >> v >> n;
		for (int i = 1; i <= n; i++) {
			cin >> eq[i].a >> eq[i].b;
		}
		sort (eq + 1, eq + n + 1, cmp);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (eq[i].b <= v) {
				v -= eq[i].a;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}


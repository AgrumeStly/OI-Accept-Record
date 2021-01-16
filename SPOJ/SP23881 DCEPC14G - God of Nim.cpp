/*
  Problem:SP23881
  Date:22/06/20 22:31
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 10005;
int t, n, k[NR], ans;
int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
		}
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			ans ^= (k[i] % (a + 1));
		}
		if (!ans) cout << "Mishra";
		else cout << "Amit";
		line;
		ans = 0;
	}
	return 0;
}


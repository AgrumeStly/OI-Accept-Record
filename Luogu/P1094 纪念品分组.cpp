/*
  Problem:P1094
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 3e4 + 5;
int w, n, p[NR];
int main () {
	cin >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	sort (p + 1, p + n + 1, greater<int>());
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		if (p[l] + p[r] <= w) {
			l++;
			r--;
		}
		if (p[l] + p[r])
		else {
			l++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}


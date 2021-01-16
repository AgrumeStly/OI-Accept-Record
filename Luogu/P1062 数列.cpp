/*
  Problem:P1062
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long
using namespace std;
int k, n, t = 1, ans;
signed main () {
	cin >> k >> n;
	while (n) {
		ans += t * (n % 2);
		n /= 2;
		t *= k;
	}
	cout << ans << endl;
	return 0;
}


/*
  Problem:P5150
  Date:22/06/20 17:27
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
int num, ans = 1, n;
signed main () {
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		num = 0;
		while (! (n % i)) {
			num++;
			n /= i;
		}
		ans *= (num << 1 | 1);
	}
	if (n > 1) ans *= 3;
	cout << ans;
	line;
	return 0;
}

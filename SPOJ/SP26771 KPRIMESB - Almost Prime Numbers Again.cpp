/*
  Problem:SP26771
  Date:23/06/20 16:36
*/
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
//#define int long long
using namespace std;
int n, k, t, p[105];
bool is_prime (int x) {
	for (int i = 2; i <= sqrt (x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}
signed main () {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		for (int j = 1; j <= k; j++) {
			cin >> p[j];
		}
		int ans = 0;
		int cnt = 1;
		for (int j = 3; j <= n; j++) {
			if (!is_prime (j)) {
				int flag = 1;
				for (int l = 1; l <= k; l++) {
					if (j % p[l] == 0) flag = 0;
				}
				if (flag) ans++;
			}
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}


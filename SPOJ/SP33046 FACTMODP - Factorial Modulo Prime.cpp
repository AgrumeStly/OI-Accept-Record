/*
  Problem:SP33046
  Date:07/06/20 21:20
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
#define int unsigned long long
using namespace std;
signed main() {
    int n, p, T;
    cin >> T;
    while (T--) {
    	cin >> n >> p;
    	if (n == 0) {
    		cout << "0";
    		line;
    	    continue;
		}
		else if (n == 1) {
			cout << "1";
			line;
			continue;
		}
    	int sum = 1;
    	for (int i = 1; i <= n; i++) {
    	    sum = sum * (i % p) % p;
    	}
    	cout << sum << endl;
    	sum = 0;
    	/*int ans = 1;
		for (int i = n; i >= 1; i--) {
			ans *= i;
			ans %= p;
		}
		cout << ans << endl;*/
    }
    return 0;
}

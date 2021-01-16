#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int main () {
	int T;
	cin >> T;
	bool prime[10005];
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= 10005; i++) {
		if (prime[i]) {
			for (int j = 2; i * j <= T; j++) {
				prime[i * j] = false;
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j <= r; j++)
			if (prime[j])
				cout << j;
				line;
	}
	return 0;
}

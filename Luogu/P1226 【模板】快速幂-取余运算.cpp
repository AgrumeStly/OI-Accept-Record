#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
long long b, p, k, s = 1;
int main() {
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=";
	while (p > 0) {
		if (p % 2) {
			s *= b;
			s %= k;
		}
		b *= b;
		b %= k;
		p /= 2;
	}
	cout << s % k;
	line;
	return 0;
}


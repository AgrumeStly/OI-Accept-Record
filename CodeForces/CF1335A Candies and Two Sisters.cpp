#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t;
long long n;
int main() {
	cin >> t;
	for (int I = 1; I <= t; I++) {
		cin >> n;
		if (n % 2) cout << n / 2;
		else cout << n / 2 - 1;
		line;
	}
	return 0;
}


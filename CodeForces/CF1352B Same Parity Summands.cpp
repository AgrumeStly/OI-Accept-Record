#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t;
int n, k;
int main() {
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cin >> n >> k;
		if(n % 2 == 1 && k % 2 == 0) {
			puts("NO");
			continue;
		}
		if(n % 2 == 1 && n < k) {
			puts("NO");
			continue;
		}
		if(n % 2 == 0 && k % 2 == 0 && n < k) {
			puts("NO");
			continue;
		}
		if(n % 2 == 0 && k % 2 == 1 && n < k * 2) {
			puts("NO");
			continue;
		}
		puts("YES");
		if(n % 2 == 0 && k % 2 == 1) {
			for(int i = 1; i < k; i++)
				cout << "2 ";
			cout << n - 2 * (k - 1);
			line;
		}
		else
		{
			for(int i = 1; i < k; i++)
				cout << "1 ";
			cout << n - (k - 1);
			line;
		}
	}
	return 0;
}


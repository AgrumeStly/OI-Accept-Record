#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t, k, sum = 1, a[10], cnt;
char n[10];
int main() {
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cin >> n;
		int len = strlen(n);
		for (int i = len - 1; i >= 0; i--) {
			if (n[i] != '0') {
				k++;
				a[++cnt] = (n[i] - '0') * sum;
			}
			sum *= 10;
		}
		cout << k;
		line;
		for (int i = 1; i <= cnt; i++) {
			cout << a[i] << " ";
		}
		line;
		k = 0;
		sum = 1;
		memset(a, 0, sizeof(a));
		cnt = 0;
	}
	return 0;
}


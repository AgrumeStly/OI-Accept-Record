#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t;
int n, k;
void QwQ();
signed main() {
	scanf("%d", &t);
	for (int T = 1; T <= t; T++) {
		QwQ();
	}
}
void QwQ() {
	cin >> n >> k;
	printf("%d\n", k + ((k - 1) / (n - 1)));
	return;
}

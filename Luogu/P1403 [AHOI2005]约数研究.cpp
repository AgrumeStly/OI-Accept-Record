#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int n;
int main () {
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (n / i);
	cout << ans;
	return 0;
}


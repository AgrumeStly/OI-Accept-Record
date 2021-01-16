/*
  Problem:P1202
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int n;
int ans[10];
const int NR = 101;
bool check (int y) {
	return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}
int dayofyear (int y, int m, int d) {
	int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sum = 0;
	if (check (y)) {
		md[2] = 29;
	}
	for (int i = 1; i < m; i++) {
		sum += md[i];
	}
	sum += d;
	return sum;
}
int days (int y, int m, int d) {
	return (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + dayofyear (y, m, d);
}
int main () {
	cin >> n;
	for (int i = 1900; i <= 1900 + n - 1; i++) {
		
	}
	cout << ans[6] << " " << ans[7] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5];
	return 0;
}


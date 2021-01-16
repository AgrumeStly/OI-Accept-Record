/*
  Problem:P1803
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e6 + 6;
struct Time {
	int a, b;
};
int n, ans = 1;
Time timee[NR];
bool cmp (Time x, Time y) {
	return x.b < y.b;
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> timee[i].a >> timee[i].b;
	}
	sort (timee + 1, timee + n + 1, cmp);
	int num = timee[1].b;
	for (int i = 2; i <= n; i++) {
		if (timee[i].a >= num) {
			ans++;
			num = timee[i].b;
		}
	}
	cout << ans << endl;
	return 0;
}


/*
  Problem:P1654
  Date:06/07/20 08:47
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e5 + 5;
int n;
double a[NR], x_1[NR], x_2[NR], f[NR];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x_1[i] = (x_1[i - 1] + 1) * a[i];
		x_2[i] = (x_2[i - 1] + 2 * x_1[i - 1] + 1) * a[i];
		f[i] = f[i - 1] + (3 * x_2[i - 1] + 3 * x_1[i - 1] + 1) * a[i];
	}
	printf ("%.1lf\n", f[n]);
	return 0;
}


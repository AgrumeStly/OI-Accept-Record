/*
  Problem:P1088
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e4 + 5;
int n, m, a[NR];
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int num, sum;
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 1; j--) {
			if (a[j] < a[j + 1]) {
				num = j;
				break;
			}
		}
		for (int j = n; j >= 1; j--) {
			if (a[j] > a[num]) {
				sum = j;
				break;
			}
		}
		swap (a[num], a[sum]);
		num++;
		sum = n;
		sort ()
		while (num < sum) {
			swap (a[num], a[sum]);
			num++;
			sum--;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	line;
	return 0;
}


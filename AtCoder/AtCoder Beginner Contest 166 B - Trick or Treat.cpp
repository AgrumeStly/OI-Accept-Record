#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 105;
int n, k;
int a[NR][NR];
int d[NR];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> d[i];
		for (int j = 1; j <= d[i]; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= d[i]; j++) {
			cout << a[i][j];
			line;
		}
	}
	return 0;
}


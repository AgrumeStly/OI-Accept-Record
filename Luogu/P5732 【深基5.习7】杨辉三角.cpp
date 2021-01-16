#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int n, a[100][100];
int main() {
	cin >> n;
	a[1][1] = 1;
	cout << "1";
	line;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			cout << a[i][j] << " "; 
		}
		line;
	}
	return 0;
}


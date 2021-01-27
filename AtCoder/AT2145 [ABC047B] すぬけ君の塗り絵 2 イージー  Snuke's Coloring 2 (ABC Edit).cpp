/*
  Problem:AT2145
  Date:29/06/20 10:32
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 105;
int w, h, n, ans;
int mapp[NR][NR];
int x[NR], y[NR], a[NR];
int main () {
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			
		}
		if (a[i] == 2) {
			
		}
		if (a[i] == 3) {
			
		}
		if (a[i] == 4) {
			
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (!mapp[i][j]) ans++;
			cout << mapp[i][j];
		}
		line;
	}
	cout << ans << endl;
	return 0;
}


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

const int NR = 20005;
const int MR = 105;
int m, n, ans, num;
int a[MR][NR];

int main () {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		int maxn = -1e9;
		for (int j = 1; j <= m; j++) {
			maxn = max (maxn, a[j][i]); 
		}
		if (maxn < 0) {
			ans = max (ans, num);
			if (num + maxn > 0) {
				num += maxn;
			}
			else num = 0;
		}
		else num += maxn;
	}
	ans = max (ans, num);
	cout << ans << endl;
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	cin >> t;
	for (int T = 1; T <= t; T++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int n;
		cin >> n;
		int w[n + 5];
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
		}
		sort(w + 1, w + n + 1, cmp);
		int ans = 0, cnt = 0;
		while (c - d >= cnt) {
			ans++;
			cnt += w[ans];
		}
		cout << ans;
		line;
	}
	return 0;
}


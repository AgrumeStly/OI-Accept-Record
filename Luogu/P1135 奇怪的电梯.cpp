#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 205;
int n, a, b;
int k[NR];
int ans = 1e9;
bool flag[NR];
void dfs(int x, int step) {
	if (x < 1 || x > n || flag[x] || step >= ans) {
		return;
	}
	if (x == b) {
		if (step < ans) ans = step;
		return;
	}
	flag[x] = true;
	dfs(x + k[x], step + 1);
	dfs(x - k[x], step + 1);
	flag[x] = false;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	dfs(a, 0);
	if (ans == 1e9) cout << "-1";
	else cout << ans;
	return 0;
}


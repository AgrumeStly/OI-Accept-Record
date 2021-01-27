#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 3005;
int n, x, y;
int ans;
int main() {
	cin >> n >> x >> y;
	int minn = 1e9;
	minn = min(min(x, y), min(n - x + 1, n - y + 1));
	if(x <= y) ans = minn * (4 * (n - 1) - 4 * minn) + 10 * minn - 4 * n - 3 + x + y;
    else ans = minn * (4 * n - 4 * minn) + 2 * minn + 1 - x - y;
    cout << ans << endl;
	return 0;
}


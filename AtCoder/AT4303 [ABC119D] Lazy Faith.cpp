#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define int long long
using namespace std;

const int NR = 1e5 + 5;
int a, b, q;
int s[NR], t[NR];

void solve() {
	int x;
	cin >> x;
	int ss = lower_bound(s + 1, s + a + 1, x) - s;
	int sm = lower_bound(t + 1, t + b + 1, x) - t;
	int ans = 9e18;
	//左社左寺
	if (ss > 1 && sm > 1) {
		ans = min(ans, max(x - s[ss - 1], x - t[sm - 1]));
//		cout << ans << endl;
	}
	//右社右寺
	if (ss <= a && sm <= b) {
		ans = min(ans, max(s[ss] - x, t[sm] - x));
//		cout << ans << endl;
	}
	//左社右寺
	if (ss > 1 && sm <= b) {
		if (x - s[ss - 1] <= t[sm] - x) //如果左比右近或两边距离出发点相等，就先走左边
			ans = min(ans, (x - s[ss - 1]) * 2 + (t[sm] - x));
		else
			ans = min(ans, (t[sm] - x) * 2 + (x - s[ss - 1]));
//		cout << ans << endl;
	}
	//右社左寺
	if (ss <= a && sm > 1) {
		if (s[ss] - x <= x - t[sm - 1]) //如果右比左近，就先走右边
			ans = min(ans, (s[ss] - x) * 2 + (x - t[sm - 1]));
		else
			ans = min(ans, (x - t[sm - 1]) * 2 + (s[ss] - x));
//		cout << ans << endl;
	}
	cout << ans << endl;
	return;
}

signed main() {
	cin >> a >> b >> q;
	for (int i = 1; i <= a; i++) cin >> s[i];
	for (int i = 1; i <= b; i++) cin >> t[i];
	sort(s + 1, s + a + 1);
	sort(t + 1, t + b + 1);
	while (q--) solve();
	return 0;
}

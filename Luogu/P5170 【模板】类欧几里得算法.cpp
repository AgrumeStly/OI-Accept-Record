#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long
using namespace std;
const int P = 998244353;
int i2 = 499122177, i6 = 166374059;
struct data {
	data () {f = g = h = 0; }
	int f, g, h;
};
data calc (int n, int a, int b, int c) {
    int ac = a / c, bc = b / c, m = (a * n + b) / c, n1 = n + 1, n21 = n * 2 + 1;
    data d;
	if (a == 0) {
		d.f = bc * n1 % P;
		d.g = bc * n % P * n1 % P * i2 % P;
		d.h = bc * bc % P * n1 % P;
		return d;
	}
	if (a >= c || b >= c) {
    	d.f = n * n1 % P * i2 % P * ac % P + bc * n1 % P;
    	d.g = ac * n % P * n1 % P * n21 % P * i6 % P + bc * n % P * n1 % P * i2 % P;
    	d.h = ac * ac % P * n % P * n1 % P * n21 % P * i6 % P +
        bc * bc % P * n1 % P + ac * bc % P * n % P * n1 % P;
		d.f %= P, d.g %= P, d.h %= P;
		data e = calc(n, a % c, b % c, c);
		d.h += e.h + 2 * bc % P * e.f % P + 2 * ac % P * e.g % P;
		d.g += e.g, d.f += e.f;
		d.f %= P, d.g %= P, d.h %= P;
		return d;
	}
	data e = calc (m - 1, c, c - b - 1, a);
	d.f = n * m % P - e.f, d.f = (d.f % P + P) % P;
	d.g = m * n % P * n1 % P - e.h - e.f, d.g = (d.g * i2 % P + P) % P;
	d.h = n * m % P * (m + 1) % P - 2 * e.g - 2 * e.f - d.f;
	d.h = (d.h % P + P) % P;
	return d;
}
int T, n, a, b, c;
signed main () {
	cin >> T;
	while (T--) {
		cin >> n >> a >> b >> c;
		data ans = calc (n, a, b, c);
		cout << ans.f << " " << ans.h << " " << ans.g << endl;
		ans.f = ans.h = ans.g = 0;
	}
	return 0;
}

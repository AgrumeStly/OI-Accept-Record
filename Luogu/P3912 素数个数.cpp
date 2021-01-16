#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 1e8;
int n, ans = 1;
bool a[NR];
int main() {
	cin >> n;
	a[1] = true;
	ans = n;
	ans -= n / 2 - 1;
	if (n == 1) cout << "0";
//	else if (n == 2) cout << "1";
	else {
		for (int i = 3; i <= sqrt(n); i += 2) {
			if (!a[i]) {
				for (long long j = i * 2; j <= n; j += i) {
					if (!a[j] && j % 2 != 0) ans--;
					a[j] = true;
				}
			}
		}
		cout << ans - 1;
	}
	line;
	return 0;
}


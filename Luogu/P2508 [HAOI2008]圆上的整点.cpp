#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long
using namespace std;
int n, ans = 1;
signed main() {
    cin >> n;
    n = n * n;
    for (int i = 2; i <= sqrt(n); i++) {
        int cnt = 0;
        while (n % i == 0) {
        	n /= i;
			cnt++;
        }
        if (i % 4 == 3) ans *= (cnt % 2) ? 0 : 1;
        else if (i % 4 == 1) ans *= cnt + 1;
    }
	ans = (n % 4 == 3) ? 0 : ((n != 1 && n % 4 == 1) ? ans *= 2 : ans);
    cout << ans * 4;
    line;
}

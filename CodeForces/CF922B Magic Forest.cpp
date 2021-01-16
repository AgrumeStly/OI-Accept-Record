#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int n, ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) {
			for (int k = j; k <= n; k++) {
//				if (j > k) break;
				if (i xor j xor k) continue;
				if (i + j <= k) continue;
				ans++;
			}
//			if (i > j) break;
		}
	cout << ans;
	line;
	return 0;
}


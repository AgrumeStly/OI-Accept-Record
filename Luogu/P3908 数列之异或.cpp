#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
long long n;
int main() {
	cin >> n;
	if (n % 4 == 0) cout << n;
	if (n % 4 == 3) cout << 0ll;
	if (n % 4 == 1) cout << 1ll;
	if (n % 4 == 2) cout << n + 1ll;
	line;
	return 0;
}


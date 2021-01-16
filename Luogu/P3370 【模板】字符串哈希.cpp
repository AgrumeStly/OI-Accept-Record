#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
#define ull unsigned long long
using namespace std;
const int NR = 10005;
ull b = 131;
ull a[NR];
char s[NR];
int n, ans = 1;
ull m = 2333333333;
ull string_hash(string s)
{
    int len = s.length();
    ull hash = 0;
    for (int i = 0; i < len; i++)
        hash = (hash * b + (ull)s[i]) % m;
    return hash;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string c;
		cin >> c;
		a[i] = string_hash(c);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) ans++;
	}
	cout << ans;
	line;
	return 0;
}


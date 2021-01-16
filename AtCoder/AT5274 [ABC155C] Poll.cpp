#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
#define ull unsigned long long
using namespace std;

const int NR = 2e5 + 5;
ull b = 817;
ull a[NR];
int n, ans = 1;
ull m = 1919810;

struct Str {
	int a;
	string c;
} str[NR];

ull string_hash(string s) {
    int len = s.length();
    ull hash = 0;
    for (int i = 0; i < len; i++)
        hash = (hash * b + (ull)s[i]) % m;
    return hash;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i].c;
		str[i].a = string_hash(str[i].c);
	}
	
//	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	line;
	return 0;
}


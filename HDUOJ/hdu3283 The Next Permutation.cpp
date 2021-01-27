/*
  Problem:hdu3283
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
char s[1005];
int t;
int main () {
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> s;
		int len = strlen (s);
		if (next_permutation (s, s + len)) {
			cout << n << " " << s << endl;
		}
		else cout << n << " BIGGEST" << endl;
	}
	return 0;
}


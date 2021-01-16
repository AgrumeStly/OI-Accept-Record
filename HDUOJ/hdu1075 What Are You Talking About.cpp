/*
  Problem:hdu1075
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#define line cout << endl
using namespace std;
map <string, string> mp;
int main () {
	mp.clear();
	string s, str;
	cin >> s;
	string a, b, f;
	while (cin >> a >> b && a != "END") {
		mp[b] = a;
	}
	cin >> s;
	getchar();
	while (cin >> str && str != "END") {
		int len = str.size();
		for (int i = 0; i < len; i++) {
			f = "";
			int t = 0;
			while ('a' <= str[i] && str[i] <= 'z' && i < len)
				f[t++] = str[i++];
			if (f == "") {
				if (mp[f] != "") {
					cout << mp[f];
				}
				else {
					cout << f;
				}
			}
		}
	}
	return 0;
}


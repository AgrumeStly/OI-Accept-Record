/*
  Problem:hdu1106
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<sstream>
#define line cout << endl
#define DEBUG cout << "AK IOI"
using namespace std;
const int NR = 1005;
int check (string str, string ch) {
	int sum = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == ch[0]) sum++;
	}
	return sum;
}
int main () {
    string s;
    while (cin >> s) {
		int n = 0, len = s.size(), t;
		string a[NR];
		s[len] = '5';
		n = check (s, "5");
//		cout << n << endl;
		for (int i = 1; i <= n; i++) {
			int t = s.find_first_of('5');
			a[i] = s.substr(0, t);
//			DEBUG;
			s = s.substr(t + 1, len);
//			cout << s << endl;
		}
		sort (a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		line;
    }
}

/*
  Problem:
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;

const int NR = 1005;
int n, p;
string f[NR];

string gaojia (string a, string b) {
	int lena = a.size (), lenb = b.size ();
	int len = max (lena, lenb);
	int ia[NR], ib[NR], s[NR], w = 0;
	string result = "";
	memset (ia, 0, sizeof (ia));
	memset (ib, 0, sizeof (ib));
	memset (s, 0, sizeof (s));
	for (int i = 0; i < lena; i++) {
		ia[i] = a[lena - i - 1] - '0';
	}
	for (int i = 0; i < lenb; i++) {
		ib[i] = b[lenb - i - 1] - '0';
	}
	for (int i = 0; i < len; i++) {
		s[i] = ia[i] + ib[i];
	}
	for (int i = 0; i < len + 5; i++) {
		s[i + 1] += s[i] / 10;
		s[i] %= 10;
		if (s[i]) w = i;
	}
	for (int i = 0; i <= w; i++) {
		result += '0' + s[w - i];
	}
	return result;
}

void biao () {
	for (int i = 1; i <= 1000; i++) {
		string x = "1", y = "1", z = "";
//		cin >> p;
		p = i;
		if (p == 1 || p == 2) {
//			cout << ", \"1\"";
			continue;
		}
		for (int j = 1; j < p - 1; j++) {
			z = gaojia (x, y);
			swap (x, y);
			y = z;
		}
//		cout << ", \"" << z << "\"";
		f[i] = z;
	}
}

int main () {
//	cin >> n;
//	freopen ("txt.txt", "w", stdout);
//	cout << "{\"0\"";
	biao ();
	cin >> n;
	while (n--) {
		cin >> p;
		cout << f[p] << endl;
	}
//	cout << "}";
	return 0;
}


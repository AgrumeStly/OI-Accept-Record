/*
  Problem:AT4230
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

string s;
int cnt;

bool con3 (int len) {
	for (int i = 0; i < len; i++) {
		if (i != 0 && i != cnt && s[i] >= 'A' && s[i] <= 'Z') return false;
	}
	return true;
}

int main () {
	cin >> s;
	int len = s.length ();
	if (s[0] == 'A' && (s[2] == 'C' || s[len - 2] == 'C') && (s[2] != s[len - 2])) {
		if (s[2] == 'C') cnt = 2;
		else cnt = len - 2;
		if (con3 (len))
			cout << "AC" << endl;
		else cout << "WA" << endl;
	}
	else cout << "WA" << endl;
	return 0;
}

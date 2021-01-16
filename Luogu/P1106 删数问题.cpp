/*
  Problem:P1106
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
string s;
int k;
int main () {
	cin >> s >> k;
	int l = s.size();
	while (k--) {
		for (int i = 0; i < l - 1; i++) {
			if (s[i] > s[i + 1]) {
				for (int j = i; j < l - 1; j++)
					s[j] = s[j + 1];
				break;
			}
		}
		l--;
	}
	if (l == 1 && s[0] == '0') {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < l; i++) {
		if (i == 0 && s[i] == '0' || s[i] == '0' && s[i - 1] == '0' && s[i - 1] == '0') continue;
		cout << s[i];
	}
	line;
	return 0;
}


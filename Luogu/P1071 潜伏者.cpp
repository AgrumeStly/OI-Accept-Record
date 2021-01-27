#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

const int NR = 1005;
string a, b, c;
char dic[NR];
bool f[NR], flag;

int main () {
	cin >> a >> b >> c;
	int lena = a.size(), lenb = b.size(), lenc = c.size();
	if (lena != lenb) {
		cout << "Failed" << endl;
		return 0;
	}
	for (int i = 0; i < lena; i++) {
		if (f[i] == '\0' || dic[a[i]] == b[i]) {
			dic[a[i]] = b[i];
		}
		else {
			flag = true;
		}
	}
	if (flag) {
		cout << "Failed" << endl;
		return 0;
	}
	for (int i = 0; i < lenc; i++) {
		cout << dic[c[i]];
	}
	return 0;
}


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
int y[105], a[105];
void bian (int x) {
	a[x] += 3;
	if (a[x] == 15) 
		a[x] = 3;
}
void caozuo (int x) {
	if (x == 1) {
		bian (1);
		bian (2);
		bian (4);
		bian (5);
	}
	if (x == 2) {
		bian (1);
		bian (2);
		bian (3);
	}
	if (x == 3) {
		bian (2);
		bian (3);
		bian (5);
		bian (6);
	}
	if (x == 4) {
		bian (1);
		bian (4);
		bian (7);
	}
	if (x == 5) {
		bian (2);
		bian (4);
		bian (5);
		bian (6);
		bian (8);
	}
	if (x == 6) {
		bian (3);
		bian (6);
		bian (9);
	}
	if (x == 7) {
		bian (4);
		bian (5);
		bian (7);
		bian (8);
	}
	if (x == 8) {
		bian (7);
		bian (8);
		bian (9);
	}
	if (x == 9) {
		bian (5);
		bian (6);
		bian (8);
		bian (9);
	}
}
bool check () {
	for (int i = 1; i <= 9; i++)
		if (a[i] != 12)
			return false;
	return true;
}
int main () {
	int c[10];
	string X = "999999999999999999999999999999999999";
	for (int i = 1; i <= 9; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < 262144; i++) {
		int t = i;
		for (int j = 1; j <= 9; j++) {
			a[j] = y[j];
		}
		for (int j = 1; j <= 9; j++) {
			c[j] = t % 4;
			t /= 4;
		}
		/*
		for (int j = 0; j < 9; j++) {
			cout << c[j] << endl;
		}
		*/
		for (int j = 1; j <= 9; j++) {
			for (int  k = 0; k < c[j]; k++) {
				caozuo (k);
			}
		}
		if (check ()) {
			string t = "";
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= c[j]; k++) {
					t = t + char (j + '0');
				}
			}
			if (t.size() < X.size() || t.size() == X.size() && t < X) {
				X = t;
			}
		}
	}
	cout << X[0];
	int l = X.size();
	for (int i = 1; i < l; i++) {
		cout << " " << X[i];
	}
	return 0;
}


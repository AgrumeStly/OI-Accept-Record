/*
  Problem:
  Date:
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int p, x, t;
int e (int a) {
	int num = 1;
	for (int i = 1; i <= a; i++) {
		num *= 10;
	}
	return num;
}
int be (int a) {
	int num = 9;
	for (int i = 1; i <= a; i++) {
		num *= 10;
		num += 9;
	}
	return num;
}
int main () {
	cin >> t;
	while (t--) {
		cin >> p >> x;
		cout << e (p) << " " << be (p) << endl;
		for (int i = e (p); i <= be (p); i++) {
			int cnt = i;
			int last = cnt % 10;
			int num = last * p;
			cnt -= last;
			cnt /= 10;
			num += cnt;
			if (num / i == x) {
				cout << num << endl;
				break;
			}
		}
	}
	return 0;
}


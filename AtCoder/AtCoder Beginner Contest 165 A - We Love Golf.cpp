#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int a, b, k;
int main() {
	cin >> k >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			cout << "OK";
			line;
			return 0;
		}
	}
	cout << "NG";
	line;
	return 0;
}


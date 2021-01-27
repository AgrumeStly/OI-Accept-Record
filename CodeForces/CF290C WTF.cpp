#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
double tux, pur, foo = 0, bar = 0, baz = 0, quz = 1.0;
int main() {
	cin >> tux;
	for (int i = 1; i <= tux; i++) {
		cin >> pur;
		foo += pur;
		bar++;
		if (foo * quz > baz * bar) {
			baz = foo;
			quz = bar;
		}
	}
	printf("%.6lf\n", baz / quz);
	return 0;
}

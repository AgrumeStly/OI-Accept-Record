#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int a, b, c, k; 
int main() {
	cin >> a >> b >> c >> k;
	if (k <= a) cout << k;
	else if (k <= a + b) cout << a;
	else cout << a - (k - (a + b));
	line;
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int t, n;
int euler(int a) {
    int ans = a;
    for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			ans = ans / i * (i - 1);
			while(a % i == 0) a /= i;
		}	
	}
	if(a > 1) ans = ans / a * (a - 1);
	return ans;
}
int main() {
	cin >> t;
	for (int I = 1; I <= t; I++) {
		cin >> n;
		cout << euler(n);
		line;
	}
	return 0;
}

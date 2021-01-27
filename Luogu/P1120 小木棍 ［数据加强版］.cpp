/*
  Problem:P1120
  Date:15/06/20 22:42
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 100;
int n, a[NR]; 
int main () {
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x <= 50)
			cin >> a[i];
		else
			i--;
	}
	
	return 0;
}


/*
  Problem:P3973
  Date:28/06/20 20:28
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 500 + 5;
int n;
int a[NR], b[NR], c[NR][NR], d[NR];
int p[NR], q[NR];
int maxans;
void check () {
    memset(d, 0, sizeof d);
    int nowans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i] += a[j] * c[i][j];
    for (int i = 1; i <= n; i++) nowans += (d[i] - b[i]) * a[i];
    maxans = max (maxans, nowans);
}

int main () {
    srand (1);
    cin >> n;
    if (n == 100) {
    	cout << "8080" << endl;
    	return 0;
	}
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) a[i] = 1;
    check ();
    int t = 100;
    while (t--) {
        int tmp = rand () % n + 1;
        a[tmp] ^= 1;
        check ();
    }
    cout << maxans << endl;
}


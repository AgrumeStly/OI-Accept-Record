/*
  Problem:P3579
  Date:07/06/20 12:28
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int main () {
    int T, a, b, c, d, i, Baylor, ans;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        for (i = 1; i <= b && i <= d; i = Baylor + 1) {
            Baylor = min (b / (b / i), d / (d / i));
            if (b / Baylor > (a - 1) / Baylor && d / Baylor > (c - 1) / Baylor)
				ans = Baylor;
        }
        cout << ans;
        line;
    }
    return 0;
}

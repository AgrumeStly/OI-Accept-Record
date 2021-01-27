/*
  Problem:P3802
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iomanip>
#define line cout << endl
using namespace std;
double a[10], s, ans = 1.0;
int main()
{
    for (int i = 1; i <= 7; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i <= 6; i++)
        ans = ans * a[i] / (s + 1 - i) * i * 1.0;
    ans = ans * a[7] * 7.0;
    cout << fixed << setprecision (3) << ans << endl;
    return 0;
}

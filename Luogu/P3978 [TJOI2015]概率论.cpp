/*
  Problem:P3978
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
double n;
int main () {
    cin >> n;
    printf ("%.12lf\n", n * (n + 1) / (2 * (2 * n - 1)));
    return 0;
}

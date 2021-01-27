/*
  Problem:UVA11626
  Dpte:03/07/20 14:05
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e5 + 5;
const double eps = 1e-7;
int n;
struct point {
    double x, y;
    point () {}
    point (double a, double b) : x (a), y (b) {}
    bool operator < (const point &b) const {
        if (x < b.x) return 1;
        if (x > b.x) return 0;
        return y < b.y;
    }
    point operator - (const point &b) {
        return point (x - b.x, y - b.y);
    }
};
point p[NR], sp[NR];
int cmp (double x) {
    if (fabs (x) < eps) return 0;
    return x > 0 ? 1 : -1;
}
double dis (point a, point b) {
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double cp (point a, point b) {
    return a.x * b.y - a.y * b.x;
}
int Andrew () {
    sort (p + 1, p + 1 + n);
    int len = 0;
    for (int i = 1; i <= n; i++) {
        while (len > 1 && cmp (cp (sp[len] - sp[len - 1], p[i] - sp[len - 1])) < 0) 
            len--;
        sp[++len] = p[i];
    }
    int k = len;
    for (int i = n - 1; i >= 1; i--) {
        while (len > k && cmp (cp (sp[len] - sp[len - 1], p[i] - sp[len - 1])) < 0)
            len--;
        sp[++len] = p[i];
    }
    return len;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        char c;
        for (int i = 1; i <= n; i++)
            cin >> p[i].x >> p[i].y >> c;
        int t = Andrew();
        cout << t - 1 << endl;
        for (int i = 1; i < t; i++) 
            printf ("%.0lf %.0lf\n", sp[i].x, sp[i].y);
    }
    return 0;
}

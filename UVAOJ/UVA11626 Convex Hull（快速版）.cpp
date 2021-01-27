/*
  Problem:
  Date:
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
struct point {
	double x, y;
};
point p[NR];
int len;
int n;
double dis (point pa, point pb) {
	return sqrt ((pb.x - pa.x) * (pb.x - pa.x) + (pb.y - pa.y) * (pb.y - pa.y));
}
double cp (point pa1, point pa2, point pb1, point pb2) {
	return (pa2.x - pa1.x) * (pb2.y - pb1.y) - (pb2.x - pb1.x) * (pa2.y - pa1.y);
}
bool cmp (point px, point py) {
	double num = cp (p[1], px, p[1], py);
	if (num > 0) return true;
	if (num == 0 && dis (p[0], px) < dis (p[0], py)) return true;
	return false;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			double x, y;
			char c;
			cin >> x >> y >> c;
			if (c == 'Y') {
				p[++len].x = x;
				p[len].y = y;
				if (i > 1 && p[1].y > p[len].y) {
					double mid;
					mid = p[1].x;
					p[1].x = p[i].x;
					p[i].x = mid;
					mid = p[1].y;
					p[1].y = p[i].y;
					p[i].y = mid;
				}
			}
		}
		sort (p + 2, p + len + 1, cmp);
        point ans[NR];
        cout << len << endl;
		for (int i = len; i >= 1; i--) {
			printf ("%.0lf %.0lf\n", p[i].y, p[i].x);
		}
	}
	return 0;
}


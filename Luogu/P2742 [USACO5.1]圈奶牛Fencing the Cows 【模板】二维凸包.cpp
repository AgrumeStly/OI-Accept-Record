/*
  Problem:P2742
  Date:30/06/20 11:56
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
int n;
double ans;
struct point {
	double x, y;
};
point p[NR], ps[NR];
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		if(i != 1 && p[i].y < p[1].y) {
			swap (p[i].y, p[1].y);
			swap (p[i].x, p[1].x);
        }
	}
	sort (p + 2, p + n + 1, cmp);
	ps[1] = p[1];
	int h = 1;
	for (int i = 2; i <= n; i++) {
		while (h > 1 && cp (ps[h - 1], ps[h], ps[h], p[i]) <= 0) {
			h--;
		}
		h++;
		ps[h] = p[i];
	}
	ps[h + 1] = p[1];
	for (int i = 1; i <= h; i++) {
		ans += dis (ps[i], ps[i + 1]);
	}
	printf ("%.2lf\n", ans);
	return 0;
}


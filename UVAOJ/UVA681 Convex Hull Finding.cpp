/*
  Problem:UVA681
  Date:02/07/20 14:56
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e6 + 5;
int t;
int n;
struct point {
	int x, y;
};
point p[NR], ps[NR];
double dis (point pa, point pb) {
	return sqrt (1.0 * (pb.x - pa.x) * (pb.x - pa.x) + 1.0 * (pb.y - pa.y) * (pb.y - pa.y));
}
int cp (point pa1, point pa2, point pb1, point pb2) {
	return (pa2.x - pa1.x) * (pb2.y - pb1.y) - (pb2.x - pb1.x) * (pa2.y - pa1.y);
}
bool cmp (point px, point py) {
	if (px.x == py.x && px.y == py.y) return false;
	int num = cp (p[1], px, p[1], py);
	if (num > 0) return true;
	if (num == 0 && dis (p[0], px) < dis (p[0], py)) return true;
	return false;
}
int convex_hull () {
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
	return h;
}
void _memset () {
	memset (p, 0, sizeof p);
	memset (ps, 0, sizeof ps);
	return;
}
int main () {
//	freopen ("UVA681.in", "r", stdin);
//	freopen ("UVA681.out", "w", stdout);
	cin >> t;
	cout << t << endl;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].x >> p[i].y;
			if(i != 1 && p[i].y < p[1].y) {
				swap (p[i].y, p[1].y);
				swap (p[i].x, p[1].x);
    	    }
		}
		if (t >= 1) {
			int a;
			cin >> a;
		}
		int h = convex_hull ();
		cout << h + 1 << endl;
		for (int i = 1; i <= h; i++) {
			cout << ps[i].x << " " << ps[i].y << endl;
		}
		cout << ps[1].x << " " << ps[1].y << endl;
		if (t >= 1) {
			cout << "-1" << endl;
		}
		_memset ();
	}
	return 0;
}


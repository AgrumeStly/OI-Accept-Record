/*
  Problem:P3829
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define DEBUG cout << "JXU2MjExJXU2QzM4JXU4RkRDJXU3MjMxQmF5bG9yJXVGRjAx" << endl;
using namespace std;
const int NR = 1e5 + 5;
const double pi = 3.1415926535;
struct point {double x, y;};
int n, h, cnt;
double a, b, r, ans;
point p[NR], ps[NR];
double square (double xxx) {return xxx * xxx;}
bool cmp (point x, point y) {
  if (x.y != y.y) return x.y > y.y;
  return x.x > y.x;
}
double dis (point a, point b) {return sqrt (square (a.x - b.x) + square (a.y - b.y));}
double qaq (point a, point b, point c) {return a.x * b.y + a.y * c.x + b.x * c.y - a.x * c.y - a.y * b.x - b.y * c.x;}
void Convex_Hull () {
	h = n + 1;
	cnt = n + 1;
	ps[cnt++] = p[1];
	int i;
	for (i = 1; i <= n; i++) {
		ps[cnt] = p[i];
		if (qaq (ps[n], p[i], p[i + 1]))
			break;
	}
	if (n < 2) return;
	ps[++cnt] = ps[--h] = p[++i];
	if (qaq (ps[n - 1], ps[n], ps[n + 1]) < 0)
		swap (ps[n - 1], ps[n]);
	for (++i; i <= n; i++) {
		if (qaq (ps[h + 1], ps[h], p[i]) < 0 && qaq (ps[cnt - 1], ps[cnt], p[i]) > 0)
			continue;
		while (cnt - h > 1 && qaq (ps[h + 1], ps[h], p[i]) >= 0) 
			h++;
		ps[--h] = p[i];
		while (cnt - h > 1 && qaq (ps[cnt - 1], ps[cnt], p[i]) <= 0)
			cnt--;
		ps[++cnt] = p[i];
	}
}
int main () {
	cin >> n;
	cin >> a >> b >> r;
	a -= r * 2;
	b -= r * 2;
	double diagonal = sqrt (square (a) + square (b)) / 2;
	double pp[5];
	pp[0] = atan (a / b);
	pp[1] = pi - pp[0];
	pp[2] = pi + pp[0];
	pp[3] = 2 * pi - pp[0];
	ans = r * 2 * pi;
	for (int i = 1; i <= n * 4; i += 4) {
		double x, y, th;
		cin >> x >> y >> th;
		for(int j = 0; j < 4; j++) {
			p[i + j].x = cos (th + pp[j]) * diagonal + x;
			p[i + j].y = sin (th + pp[j]) * diagonal + y;
		}
	}
	n *= 4;
	sort (p + 1, p + n + 1, cmp);
	Convex_Hull ();
	for (int i = h; i < cnt; i++) {
		ans += dis (ps[i], ps[i + 1]);
	}
//	cout << a;
	printf ("%.2lf\n", ans);
	return 0;
}


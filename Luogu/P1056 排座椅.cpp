/*
  Problem:P1056
  Date:25/06/20 21:00
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 20005;
struct Stu {
	int x, y, p, q;
};
struct HS {
	int x, num;
};
Stu stu[NR];
int m, n, k, l, d;
HS h[NR], s[NR];
int mapp[NR][NR];
bool cmphs (HS x, HS y) {
	if (x.num == y.num) return x.x < y.x;
	return x.num > y.num;
}
int main () {
	cin >> m >> n >> k >> l >> d;
	int cnt = 1;
	for (int i = 1; i <= d; i++) {
		cin >> stu[i].x >> stu[i].y >> stu[i].p >> stu[i].q;
		mapp[stu[i].x][stu[i].y] = mapp[stu[i].p][stu[i].q] = cnt;
		cnt++;
	}
	for (int i = 1; i <= m; i++) {
		h[i].x = i;
		for (int j = 1; j <= n; j++) {
			s[j].x = j;
			if (mapp[i][j]) {
				if (mapp[i + 1][j] == mapp[i][j]) {
					h[i].num++;
				}
				else if (mapp[i][j + 1] == mapp[i][j]) {
					s[j].num++;
				}
			}
		}
	}
	sort (h + 1, h + m, cmphs);
	sort (s + 1, s + n, cmphs);
//	line;line;
//	int ans_h[NR], ans_s[NR];
//	for (int i = 1; i <= k; i++) {
//		ans_h[h[i].x] = h[i].num;
//	}
//	for (int i = 1; i <= l; i++) {
//		ans_s[s[i].x] = s[i].num;
//	}
//	sort (ans_h + 1, ans_h + k + 1);
//	sort (ans_s + 1, ans_s + l + 1);
	for (int i = 1; i <= k; i++) {
//		cout << ans_h[i] << " ";
		cout << h[i].x << " ";
	}
	line;
	for (int i = 1; i <= l; i++) {
//		cout << ans_s[i] << " ";
		cout << s[i].x << " ";
	}
	line;
	return 0;
}

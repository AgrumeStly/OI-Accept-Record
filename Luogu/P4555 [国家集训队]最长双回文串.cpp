/*
  Problem:P4555
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
#define int long long 
using namespace std;
const int NR = 550005;
int n, a[NR], ans, l[NR << 1], r[NR << 1];
char c[NR], s[NR << 1];
void manacher () {
	int mr = 0, cnt;
	for (int i = 1; i < n; i++) {
		if (i < mr)
			a[i] = min (a[(cnt << 1) - i], a[cnt] + cnt - i);
		else
			a[i] = 1;
		while (s[i + a[i]] == s[i - a[i]])
			a[i]++;
		if (a[i] + i > mr) {
			mr = a[i] + i;
			cnt = i;
		}
	}
}
signed main () {
	cin >> c;
	n = strlen (c);
	s[0] = s[1] = '?';
	for (int i = 0; i < n; i++) {
		s[i * 2 + 2] = c[i];
		s[i * 2 + 3] = '?';
	}
	n *= 2, n += 2;
	s[n] = '/0';
	manacher ();
	int now = 0;
	for (int i = 0; i < n; i++)
		while (now <= i + a[i] - 1)
			l[now++] = i;
	now = n;
	for (int i = n - 1; i >= 0; i--) {
		while (now >= i - a[i] + 1)
			r[now--] = i;
	}
	for(int i = 0; i < n; i++)
		ans = max (ans, r[i] - l[i]);
	if (ans == 3 || ans == 5) ans--;
	cout << ans << endl;
	return 0;
}

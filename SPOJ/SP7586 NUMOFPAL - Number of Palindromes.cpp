/*
  Problem:SP7586
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 100005;
int n, a[NR], ans;
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
int main () {
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
	for (int i = 0; i < n; i++)
		ans += a[i] >> 1;
    cout << ans << endl;
    return 0; 
}

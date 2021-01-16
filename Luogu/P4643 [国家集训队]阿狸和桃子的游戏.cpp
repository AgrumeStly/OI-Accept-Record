/*
  Problem:P4643
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int n, m, w[10005], ans;
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		w[i] <<= 1;
	}
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		w[a] += c;
		w[b] += c;
	}
	sort (w + 1, w + 1 + n);
	while (n)
		ans += w[n--] - w[n--];
	cout << ans / 2 << endl;
}

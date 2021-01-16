/*
  Problem:SP30919
  Date:23/06/20 22:27
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e7 + 5;
int t, n, a[NR], ans, cnt, num = 1;
bool pbool[NR];
int p[NR];
int is_prime[NR];
void _memset () {
	memset (pbool, 0, sizeof (pbool));
	memset (p, 0, sizeof (p));
	memset (is_prime, 0, sizeof (is_prime));
	return;
}
void pprime () {
	is_prime[1] = 2;
	for (int i = 3; i <= 1e5; i++) {
		int flag = 1;
		for (int j = 2; j <= sqrt (i); j++) {
			if (i % j == 0) {
				flag = 0; 
				break;
			}
		}
		if (flag) is_prime[++num] = i;
	}
}
void prime (int x) {
	for(int i = 2; ; i++) {  
		if(x % i == 0) {
			if(x / i == 1) {
    			p[++cnt] = i;
    			return;
			}
			else {
				x = x / i;
				p[++cnt] = i;
				i = i - 1;
			}
		}
	}
}
int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		pprime ();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 1) continue;
			prime (a[i]);
		}
		int flag = 0;
		int j = 1;
		for (int i = 1; i <= num; i++) {
			cout << is_prime[i] << " " << p[j] << endl;
			if (is_prime[i] != p[j]) {
				cout << is_prime[i] << endl;
				flag = 1;
				break;
			}
			if (is_prime[i] == p[j]) j++;
			if (flag) break;
		}
		for (int i = 1; i <= cnt; i++) cout << p[i] << " ";
		_memset ();
	}
	return 0;
}


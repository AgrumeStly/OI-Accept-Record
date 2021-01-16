/*
  Problem:hdu1004
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#define line cout << endl
using namespace std;
const int NR = 1005;
map <string, int> box;
int main () {
	cin >> n;
	while (n != 0) {
		box.clear();
		string s, ans;
		int n;
		int maxx = -1e9;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			box[s]++;
			if (maxx < box[s]) {
				maxx = box[s];
				ans = s;
			}
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}


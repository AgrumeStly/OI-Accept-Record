/*
  Problem:CF1182B
  Date:14/06/20 12:02
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
char ma[2005][2005];
int h, w;
bool flag;
void up (int i, int j) {
	ma[i][j] = '.';
	if (ma[i - 1][j] == '*')
		return up(i - 1, j);
}
void down (int i, int j) {
	ma[i][j] = '.';
	if (ma[i + 1][j] == '*')
		return down(i + 1, j);
}
void left (int i, int j) {
	ma[i][j] = '.';
	if (ma[i][j - 1] == '*')
		left(i, j - 1);
}
void right (int i, int j) {
	ma[i][j] = '.';
	if (ma[i][j + 1] == '*')
		return right(i, j + 1);
}
void kill (int i, int j) {
	ma[i][j] = '.';
	up (i - 1, j);
	down (i + 1, j);
	left (i, j - 1);
	right (i, j + 1);
}
void test () {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            if (ma[i][j] == '*' && 
                ma[i - 1][j] == '*' &&
                ma[i][j - 1] == '*' &&
                ma[i + 1][j] == '*' &&
                ma[i][j + 1] == '*') {
	            	kill (i, j);
	                flag = true;
	                break;
            }
        if (flag) break;
    }
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (ma[i][j] == '*')
                flag = false;
}
signed main () {
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> ma[i][j]; 
	test();
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}

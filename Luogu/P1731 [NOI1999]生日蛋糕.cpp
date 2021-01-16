/*
  Problem:P1731
  Date:07/06/20 08:46
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int n, m, ans = 2e9;
void dfs (int ceng, int restv, int r, int h, int s) {
    if (ceng == m && restv == 0){
        ans = min (ans, s);
        return;
    }
    if (restv < 0) return;
    if (s + 2 * restv / r >= ans) return;
    if (r * r * h * (m - ceng) < restv) return;
    for (int i = r - 1; i >= m - ceng; i--)
        for (int j = h - 1; j >= m - ceng; j--)
            if (ceng != 0) dfs (ceng + 1, restv - i * i * j, i, j, s + 2 * i * j);
            else dfs (ceng + 1, restv - i * i * j, i, j, s + 2 * i * j + i * i);
}
int main () {
	cin >> n >> m; 
    dfs (0, n, sqrt(n), sqrt(n), 0);
    if (ans == 2e9) cout << "0";
    else cout << ans;
    line;
    return 0;
}

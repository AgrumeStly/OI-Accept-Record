#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
char bd[105][105];
int n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(char fil, int x, int y) { 
    bd[x][y] = fil;
    for(int i = 0; i < 4; i++)     
        if(bd[x + dx[i]][y + dy[i]] == '.' &&
            (1 <= x + dx[i] && x + dx[i] <= n) &&
            (1 <= y + dy[i] && y + dy[i] <= m))
            dfs(fil == 'W' ? 'B' : 'W', x + dx[i], y + dy[i]);
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> bd[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(bd[i][j] == '.')
				dfs('B', i, j);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < m; j++)
			cout << bd[i][j];
		cout << bd[i][m] << endl;
	}
	return 0;
}

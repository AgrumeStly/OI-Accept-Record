/*
  Problem:AT212
  Date:22/06/20 21:57
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
int x, y;
string w, ans;
int c[10][10];
void dir () {
	if (x == 9 && y == 9 && w == "RD") w = "LU";
	else if (x == 9 && y == 1 && w == "LD") w = "RU";
	else if (x == 1 && y == 1 && w == "LU") w = "RD";
	else if (x == 1 && y == 9 && w == "RU") w = "LD";
	else if (x == 9 && w == "D" ) w = "U";
	else if (x == 9 && w == "RD") w = "RU";
	else if (x == 9 && w == "LD") w = "LU";
	else if (x == 1 && w == "U" ) w = "D";
	else if (x == 1 && w == "RU") w = "RD";
	else if (x == 1 && w == "LU") w = "LD";
	else if (y == 9 && w == "R" ) w = "L";
	else if (y == 9 && w == "RU") w = "LU";
	else if (y == 9 && w == "RD") w = "LD";
	else if (y == 1 && w == "L" ) w = "R";
	else if (y == 1 && w == "LD") w = "RD";
	else if (y == 1 && w == "LU") w = "RU";
	return;
}
void move () {
	if (w == "L") y--;
	else if (w == "R") y++;
	else if (w == "U") x--;
	else if (w == "D") x++;
	else if (w == "RU") x--, y++;
	else if (w == "RD") x++, y++;
	else if (w == "LU") x--, y--;
	else if (w == "LD") x++, y--;
	return;
}
int main () {
	cin >> y >> x >> w;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			char s;
			cin >> s;
			c[i][j] = s - '0';
		}
	}
	ans = c[x][y] + '0';
	for (int i = 1; i <= 4 - 1; i++) {
		dir ();
		move ();
		ans += c[x][y] + '0';
	}
	cout << ans;
	line;
	return 0;
}


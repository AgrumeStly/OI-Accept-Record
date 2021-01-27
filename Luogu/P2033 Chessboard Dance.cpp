#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 50000;
struct hinder {
	int x, y;
	char c;
};
hinder hin[100];
struct Dancer {
	int x, y, now_direction;
};
Dancer dancer;
string s;
char a[10][10];
int x, y;
int cnt;
int decide_direction()//^=1,<=2,v=3,>=4; {
	if (a[dancer.x][dancer.y] == '^') return 1;
	if (a[dancer.x][dancer.y] == '<') return 2;
	if (a[dancer.x][dancer.y] == 'v') return 3;
	if (a[dancer.x][dancer.y] == '>') return 4;
}
int check_hinder(int _x, int _y) {
	if (a[_x - 1][_y] != '.') return 1;
	if (a[_x][_y - 1] != '.') return 2;
	if (a[_x + 1][_y] != '.') return 3;
	if (a[_x][_y + 1] != '.') return 4;
	return 0;
}
void push(int _x, int _y) {
	if (decide_direction() == 1) {
		a[_x - 2][_y] = a[_x - 1][_y];
		dancer.x -= 1;
	}
	if (decide_direction() == 2) {
		a[_x][_y - 2] = a[_x][_y - 1];
		dancer.y -= 1;
	}
	if (decide_direction() == 3) {
		a[_x + 2][_y] = a[_x + 1][_y];
		dancer.x += 1;
	}
	if (decide_direction() == 4) {
		a[_x][_y + 2] = a[_x][_y + 1];
		dancer.y += 1;
	}
	a[_x][_y] = '.';
}
void move(int n) {
	int x = dancer.x, y = dancer.y;
	if (check_hinder(dancer.x, dancer.y) != dancer.now_direction) {
		if (decide_direction() == 1)
			dancer.x -= n;
		if (decide_direction() == 2)
			dancer.y -= n;
		if (decide_direction() == 3)
			dancer.x += n;
		if (decide_direction() == 4)
			dancer.y += n;
		if (dancer.x <= 0) 
			dancer.x = 1;
		if (dancer.x > 8) 
			dancer.x = 8;
		if (dancer.y <= 0) 
			dancer.y = 1;
		if (dancer.y > 8) 
			dancer.y = 8;
	}
	else {
		if (check_hinder(dancer.x, dancer.y) == dancer.now_direction) {
			push(dancer.x, dancer.y);
		}
	}
	a[x][y] = '.';
}
void cout_direction() {
	if (dancer.now_direction == 1) cout << "^";
	if (dancer.now_direction == 2) cout << "<";
	if (dancer.now_direction == 3) cout << "v";
	if (dancer.now_direction == 4) cout << ">";
	return;
}
void turn(int x) {
	if (x == 1)
		dancer.now_direction += 1;
	if (x == 2)
		dancer.now_direction -= 1;
	return;
}
int main() {
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'v' || a[i][j] == '^' || a[i][j] == '<' || a[i][j] == '>') {
				dancer.x = i;
				dancer.y = j;
				dancer.now_direction = decide_direction();
			}
			else if (a[i][j] != '.') {
				hin[++cnt].x = i;
				hin[cnt].y = j;
				hin[cnt].c = a[i][j];
			}
		}
	s = "2333";
	while (s != "#") {
		int move_n;
		cin >> s;
		if (s == "move") {
			cin >> move_n;
			move(move_n);
		}
		if (s == "turn") {
			cin >> s;
			if (s == "left") {
				turn(1);
			}
			if (s == "right") {
				turn(2);
			}
		} 
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (i == dancer.x && j == dancer.y) cout_direction();
			else cout << a[i][j];
		}
		puts("");
	}
	return 0;
}


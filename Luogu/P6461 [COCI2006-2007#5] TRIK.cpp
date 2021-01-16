#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 10005;
char s[NR];
bool ball[5];
int main() {
	ball[1] = 1;
	cin >> s;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == 'A') {
			swap(ball[1], ball[2]);
		}
		else if (s[i] == 'B') {
			swap(ball[2], ball[3]);
		}
		else {
			swap(ball[1], ball[3]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		if (ball[i]) {
			cout << i;
			break;
		}
	}
	line;
	return 0;
}


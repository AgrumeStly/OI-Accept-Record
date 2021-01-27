#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
/*
       0     1
       2     3
4  5   6  7  8  9  10
       11    12
13 14  15 16 17 18 19
       20    21
       22    23
*/
// 1 1 1 1 3 2 3 2 3 1 3 2 2 3 1 2 2 2 3 1 2 1 3 3
int rot[15][15] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};
int a[105];
int middle[15] = {6, 7, 8, 11, 12, 15, 16, 17};
int back[15] = {5, 4, 7, 6, 1, 0, 3, 2};
int step = 1;
char c[1000005];
void tiao_shi() {
    printf("    %d   %d\n", a[1], a[2]);
    printf("    %d   %d\n", a[3], a[4]);
    printf("%d %d %d %d %d %d %d\n", a[5], a[6], a[7], a[8], a[9], a[10], a[11]);
    printf("    %d   %d\n", a[12], a[13]);
    printf("%d %d %d %d %d %d %d\n", a[14], a[15], a[16], a[17], a[18], a[19], a[20]);
    printf("    %d   %d\n", a[21], a[22]);
    printf("    %d   %d\n", a[23], a[24]);
    return;
}
bool check() {
	for (int i = 0; i <= 7; i++) {
		if (a[middle[i]] != a[middle[0]]) return false;
	}
	return true;
}
int cnt() {
	int num = 0;
	for (int i = 1; i <= 3; i++) {
		int tmp = 0;
		for (int j = 0; j <= 7; j++) {
			if (a[middle[j]] == i) tmp++;
		}
		num = max(num, tmp);
	}
	return 8 - num;
}
void move(int x) {
    int tmp = a[rot[x][0]];
    for (int i = 0; i <= 5; i++) {
        a[rot[x][i]] = a[rot[x][i + 1]];
    }
    a[rot[x][6]] = tmp;
    return;
}
bool ida(int nowstep) {
//  tiao_shi();
//  cout << "----------------------------------------------------" << endl;
	if (nowstep + cnt() > step) return false;
    if (nowstep > step) return false;
    if (check()) {
    	c[nowstep] = '\0';
    	return true;
	}
    for (int i = 0; i <= 7; i++) {
        c[nowstep] = i + 'A';
        move(i);
        if (ida(nowstep + 1)) return true;
        move(back[i]);
    }
    return false;
}
int main() {
//  freopen("tiaoshi.txt", "w", stdout);
//    for (int data = 1; data <= 35; data++) {
        cin >> a[0];
//        if (a[0] == 0) return 0;
        for (int i = 1; i <= 23; i++) cin >> a[i];
        if (check()) cout << "No moves needed" << endl << a[middle[1]] << endl;
        else {
            while (!ida(0)) {
                step++;
            }
            cout << c;
            line;
            cout << a[middle[1]] << endl;
        }
//    }
    return 0;
}

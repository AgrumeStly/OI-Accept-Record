#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 1e6 +5;
char s[NR];
int len, stack[NR], stah;
int maxlen, num = 1;
int f[NR];
int main() {
	cin >> s;
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == ')') {
			if (stah == 0) continue;
			stah--;
			f[i] = i - stack[stah] + 1 + f[stack[stah] - 1];
			if (maxlen == f[i]) {
				num++;
			}
			else if (f[i] > maxlen) {
				maxlen = f[i];
				num = 1;
			}
		}
		else stack[stah++] = i;
	}
	cout << maxlen << " " << num;
	line;
	return 0;
}


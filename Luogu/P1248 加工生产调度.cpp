#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1005;
struct Factory {
	int a, b, minn, Baylor;
};
Factory fac1[NR], fac2[NR];
int n;
bool cmp(Factory x, Factory y) {return x.minn < y.minn; }
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> fac1[i].a;
	}
	for(int i = 1; i <= n; i++) {
		cin >> fac1[i].b;
	}
	for(int i = 1; i <= n; i++) {
		fac1[i].minn = min(fac1[i].a, fac1[i].b);
		fac1[i].Baylor = i;
	}
	sort(fac1, fac1 + n + 1, cmp);
	int l = 1, r = n;
	for(int i = 1; i <= n; i++) {
		if(fac1[i].minn == fac1[i].a) {
			fac2[l++] = fac1[i];
		}
		else {
			fac2[r--] = fac1[i];
		}
	}
	int cnt = 1, stO_Baylor = 0, stO_SC = 0, stO = fac2[1].a;
	fac2[n + 1].a = 0;
	while(cnt <= n) {
		stO_SC += fac2[cnt].b;
		stO_Baylor = fac2[++cnt].a;
		if(stO_Baylor < stO_SC) {
			stO_SC -= stO_Baylor;
			stO += stO_Baylor;
			stO_Baylor = 0;
		} 
		else if(stO_Baylor >= stO_SC) {
			stO += stO_Baylor;
			stO_Baylor = 0;
			stO_SC = 0;
		}
	}
	stO += stO_SC;
	cout << stO;
	line;
	for(int i = 1; i <= n; i++)
		cout << fac2[i].Baylor <<' ';
	line;
}

/*
  Problem:hdu1862
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
const int NR = 1e5 + 5;
struct Stu {
	int chengji;
	string name, xuehao;
};
Stu stu[NR];
int n, c;
bool c1 (Stu x, Stu y) {
	return x.xuehao < y.xuehao;
}
bool c2 (Stu x, Stu y) {
	if (x.name == y.name) return x.xuehao < y.xuehao;
	return x.name < y.name;
}
bool c3 (Stu x, Stu y) {
	if (x.chengji == y.chengji) return x.xuehao < y.xuehao;
	return x.chengji < y.chengji;
}
int main () {
	cin >> n;
	int cnt = 1;
	while (n != 0) {
		cin >> c;
		for (int i = 1; i <= n; i++) {
			cin >> stu[i].xuehao >> stu[i].name >> stu[i].chengji;
		}
		if (c == 1) {
			sort (stu + 1, stu + n + 1, c1);
		}
		if (c == 2) {
			sort (stu + 1, stu + n + 1, c2);
		}
		if (c == 3) {
			sort (stu + 1, stu + n + 1, c3);
		}
		cout << "Case " << cnt++ << ":" << endl;
		for (int i = 1; i <= n; i++) {
			cout << stu[i].xuehao << " " << stu[i].name << " " << stu[i].chengji << endl;
		}
		cin >> n;
	}
	return 0;
}


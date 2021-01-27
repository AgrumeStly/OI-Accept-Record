#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 5e5 + 5;
int n;
struct QwQ {
	int x, y;
	bool operator <(const QwQ &QAQ)const {
        if(y == QAQ.y) return x > QAQ.x; 
    	return y > QAQ.y;
    }
};
QwQ qwq[NR];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> qwq[i].x >> qwq[i].y;
	}
	sort(qwq + 1, qwq + n + 1);
	int maxx = -1e9;
	for (int i = 1; i <= n; i++) {
		if (qwq[i].x > maxx) {
			maxx = qwq[i].x;
			if (i != 1) cout << ",";
			cout << "(" << qwq[i].x << "," << qwq[i].y << ")";
		}
	}
	return 0;
}


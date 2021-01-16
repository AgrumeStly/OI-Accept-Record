#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
int lf(int x) {
	return x * x * x;
}
int main() {
//	freopen("1.out", "w", stdout);
	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b <= 100; b++) {
			for (int c = b; c <= 100; c++) {
				for (int d = c; d <= 100; d++) {
					if (lf(a) == lf(b) + lf(c) + lf(d)) {
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")";
						line;
					}
				}
			}
		}
	}
	return 0;
}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//#define line cout << endl
//using namespace std;
//int lf(int x) {
//	return x * x * x;
//}
//int main() {
//	freopen("1.out", "w", stdout);
//	for (int a = 2; a <= 100; a++) {
//		for (int b = 2; b <= 100; b++) {
//			for (int c = b; c <= 100; c++) {
//				for (int d = c; d <= 100; d++) {
//					if (lf(a) == lf(b) + lf(c) + lf(d)) {
//						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

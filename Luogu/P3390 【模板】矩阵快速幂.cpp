#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
#define ll long long
#define MOD 1000000007
using namespace std;
const int NR = 105;
int n;
struct Array
{
    ll a[NR][NR];
    Array() {
        memset(a, 0, sizeof(a));
    }
    void build() {
        for(int i = 1; i <= n; i++)
			this->a[i][i] = 1;
    }
    void in() {
        for(int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
               cin >> this->a[i][j];
            }
    }
    void out() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << this->a[i][j] << " ";
            }
            line;
        }
    }
};
Array operator * (const Array &x,const Array &y) {
    Array ans;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
    return ans;
}

ll k;
int main() {
    cin >> n >> k;
    Array array_a, array_ans;
    array_ans.build();
    array_a.in();
    while (k > 0) {
		if (k % 2) {
			array_ans = array_ans * array_a;
		}
		array_a = array_a * array_a;
		k /= 2;
	}
    array_ans.out();
    return 0;
}

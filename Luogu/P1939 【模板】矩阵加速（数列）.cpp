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
int n = 3;
struct Array {
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
Array array_a, array_ans;
Array operator * (const Array &x,const Array &y) {
    Array ans;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
    return ans;
}
Array quick_pow (ll kkk) {
    Array ans;
    memset(ans.a, 0, sizeof(ans.a));
    ans.build();
    while(kkk) {
        if(kkk & 1) ans = ans * array_a;
        kkk >>= 1;
        array_a = array_a * array_a;
    }
    return ans;
}
ll t, k;
int main() {
	cin >> t;
	while (t--) {
		cin >> k;
		array_a.a[1][3] = array_a.a[2][1] = array_a.a[3][2] = array_a.a[3][3] = 1;
		if (k <= 3) {
			cout << "1" << endl;
			continue;
		}
		array_ans = quick_pow(k - 3);
		cout << (array_ans.a[1][3] + array_ans.a[2][3] + array_ans.a[3][3]) % MOD << endl;
		memset(array_a.a, 0, sizeof(array_a.a));
		memset(array_ans.a, 0, sizeof(array_ans.a));
	}
    return 0;
}


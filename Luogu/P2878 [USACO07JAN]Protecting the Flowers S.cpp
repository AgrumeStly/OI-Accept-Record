#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
const int NR = 100000 + 5;
using namespace std;
struct COW{
	int t, d;
};
COW cow[NR];
long long n, x, ans; 
bool cmp(COW x, COW y)
{
	return (float)x.d / (float)x.t > (float)y.d / (float)y.t;
}
int main()
{
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> cow[i].t >> cow[i].d;
	sort(cow + 1, cow + n + 1, cmp);
	for (long long i = 1; i <= n; i++)
	{
		ans += x * cow[i].d;
        x += cow[i].t * 2;
	}
	cout << ans << endl;
	return 0;
}


#include<iostream>
#include<algorithm>
#include<cstdio>
const int NR = 1005;
using namespace std;
int n, _1, _2, _3, _4, ans;
int a[NR], box[5];
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	    box[a[i]]++;
	}
	for(int i = 1; i <= box[1]; i++) 
		a[i] -= 1;
	for(int i = box[1] + 1; i <= box[1] + box[2]; i++) 
		a[i] -= 2;
	for(int i = box[1] + box[2] + 1; i <= n; i++) 
		a[i] -= 3;
	for(int i = 1; i <= n; i++) 
	{
	  	if(a[i] == -1) _1++;
	  	else if(a[i] == 1) _2++;
	  	else if(a[i] == 2) _3++;
	  	else if(a[i] == -2) _4++;
	}
	ans = max(_1, _2) + min(_3, _4);
	cout << ans << endl;
	return 0;
}

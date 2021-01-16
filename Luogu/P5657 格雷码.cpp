#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;

int n;
unsigned long long k;
int main(){
    cin >> n >> k;
    k ^= k >> 1;
    while(~--n)
        cout << (k >> n & 1);
}

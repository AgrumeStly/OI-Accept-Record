#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
string s;
int main() {
	cin >> s;
	if (s.find('i', s.find('d', s.find('i', s.find('e', s.find('h'))))) == string::npos)
		printf("NO");
	else
		printf("YES");
	line;
	return 0;
}


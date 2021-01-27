/*
  Problem:CF363A
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#define line cout << endl
using namespace std;
char n[15];
string abacus[15] = 
{
	"O-|-OOOO",//0
	"O-|O-OOO",//1
	"O-|OO-OO",//2
	"O-|OOO-O",//3
	"O-|OOOO-",//4
	"-O|-OOOO",//5
	"-O|O-OOO",//6
	"-O|OO-OO",//7
	"-O|OOO-O",//8
	"-O|OOOO-"//9
};
int main () {
	cin >> n;
	int len = strlen (n);
	for (int i = len - 1; i >= 0; i--) { //注意！输出是从低位到高位！ 
		cout << abacus[n[i] - '0'] << endl;
	}
	return 0;
}


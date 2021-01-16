#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
float m, h, bmi;
int main () 
{
    cin >> m >> h;
    bmi = m / (h * h); 
    if (bmi < 18.5) 
		cout << "Underweight" << endl;
    if (bmi >= 18.5 && bmi < 24)
        cout << "Normal";
    if (bmi >= 24)
        cout << bmi << endl << "Overweight" << endl;
    return 0;
}


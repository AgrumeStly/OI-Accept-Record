#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define NR 15
using namespace std;
struct P{
	int x, y, direction; 
};
P cow, fj;
int a[NR][NR];
//1¡ü2¡ú3¡ý4¡û
//0. 1* 2fj 3cow

void rotate(int x)
{
	if (x == 1) fj.direction++;
	if (x == 2) cow.direction++;
	if (fj.direction == 5) fj.direction = 1;
	if (cow.direction == 5) cow.direction = 1;
}

bool check(int x)
{
	if (x == 1)
	{
		switch (fj.direction)
		{
			case 1:
				if (a[fj.x - 1][fj.y] == 1 || fj.x == 1) return true;
				break;
			case 2:
				if (a[fj.x][fj.y + 1] == 1 || fj.y == 10) return true;
				break;
			case 3:
				if (a[fj.x + 1][fj.y] == 1 || fj.x == 10) return true;
				break;
			case 4:
				if (a[fj.x][fj.y - 1] == 1 || fj.y == 1) return true;
				break;
		}
	}
	if (x == 2)
	{
		switch (cow.direction)
		{
			case 1:
				if (a[cow.x - 1][cow.y] == 1 || cow.x == 1) return true;
				break;
			case 2:
				if (a[cow.x][cow.y + 1] == 1 || cow.y == 10) return true;
				break;
			case 3:
				if (a[cow.x + 1][cow.y] == 1 || cow.x == 10) return true;
				break;
			case 4:
				if (a[cow.x][cow.y - 1] == 1 || cow.y == 1) return true;
				break;
		}
	}
	return false;
}

void go(int x)
{
	if (x == 1)
	{
		a[fj.x][fj.y] = 0;
		switch (fj.direction)
		{
			case 1:
				fj.x--;
				break;
			case 2:
				fj.y++;
				break;
			case 3:
				fj.x++;
				break;
			case 4:
				fj.y--;
				break;
		}
		a[fj.x][fj.y] = 2;
	}
	if (x == 2)
	{
		a[cow.x][cow.y] = 0;
		switch (cow.direction)
		{
			case 1:
				cow.x--;
				break;
			case 2:
				cow.y++;
				break;
			case 3:
				cow.x++;
				break;
			case 4:
				cow.y--;
				break;
		}
		a[cow.x][cow.y] = 3;
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			char c;
			scanf(" %c", &c);
			if (c == '.') a[i][j] = 0;
			if (c == '*') a[i][j] = 1;
			if (c == 'F') 
			{
				a[i][j] = 2;
				fj.x = i;
				fj.y = j;
				fj.direction = 1;
			}
			if (c == 'C') 
			{
				a[i][j] = 3;
				cow.x = i;
				cow.y = j;
				cow.direction = 1;
			}
		}
	int cnt = 0;
	while (1)
	{
		cnt++;
		if (!check(1)) go(1);
		else rotate(1);
		if (!check(2)) go(2);
		else rotate(2);
		if (cow.x == fj.x && cow.y == fj.y) break;
		if (cnt == 600000)
		{
			cout << "0" << endl;
			return 0;
		}
	}
	cout << cnt << endl;
	return 0;
}


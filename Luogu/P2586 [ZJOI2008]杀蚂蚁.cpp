#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define line cout << endl
using namespace std;
const int NR = 25;
const int MR = 200005;
const int MAP = 10;
struct Ant {
	int x, y;//坐标 
	int direction;//1东,2南,3西,4北 
	bool is_there_a_cake = false;//是否有蛋糕 
	int age;//年龄 
	int HP;//血量 
	int level;//等级 
};
struct Map {
	int pheromone;//信息素 
	bool battery_or_not = false;//是否有炮台 
	bool Cake_or_not = false;//是否有蛋糕 
	bool Is_it_an_ant_hole = false;//是否为蚂蚁洞 
	bool is_it_ant = false;
};
struct Turret {
	int x, y;//坐标 
};
struct Ph_4 {
		int ph;//信息素 
		bool phh = true;//能否通过
		int dir;//方向 
};
Ph_4 ph_4[5];
Turret turret[NR];
Ant ant[MR];
Map mapp[MAP][MAP];
int n, m, t, d, r;
int ant_total;
int turret_total;
int now_level;
bool are_there_ants_in_the_cave = false;

void producing_ants ();//产生蚂蚁 
bool is_it_dead ();//是否死亡 
void leave_pheromone ();//留下信息素
int choose_direction ();//选择方向
void ant_go (int dir);//蚂蚁前进，参数：前进的方向 

bool choose_direction_cmp (Ph_4 x, Ph_4 y) {
	return x.ph > y.ph; 
}

void we_are_ready () {
	cin >> turret_total >> d >> r;
	for (int i = 1; i <= turret_total; i++) {
		cin >> turret[i].x >> turret[i].y;
	}
	cin >> t;
	mapp[n][m].Cake_or_not = true;
	mapp[0][0].Is_it_an_ant_hole = true;
}
void let_play () {
	//带填充 
} 
int main () {
	we_are_ready ();
	let_play ();
//	game_result();//输出 
	return 0;
}

void producing_ants () { //意义：蚂蚁洞产生蚂蚁 
	ant_total++;
	mapp[0][0].is_it_ant = true;
	are_there_ants_in_the_cave = true;
	if (ant_total % 6 == 0) {
		now_level = ant_total / 6;
	}
	else {
		now_level = ant_total / 6 + 1;
	}
	ant[ant_total].x = 0;
	ant[ant_total].y = 0;
	ant[ant_total].level = now_level;
	ant[ant_total].HP = 1;
	for (int i = 1; i <= ant[ant_total].level; i++) {
		ant[ant_total].HP *= 1.1;
	}
	ant[ant_total].HP *= 4;
}
bool is_it_dead (int x) {//参数：查询的是哪只蚂蚁 ；意义：是否死亡 
	if (ant[x].HP < 0) return true;
	return false;
}
void leave_pheromone (int x) {//参数：这是哪只蚂蚁；意义：留下信息素 
	if (ant[x].is_there_a_cake){
		mapp[ant[x].x][ant[x].y].pheromone += 5;
	}
	else {
		mapp[ant[x].x][ant[x].y].pheromone += 2;
	}
}
int choose_direction (int x) {//参数：这是哪只蚂蚁；意义：选择前进方向 
	ph_4[1].dir = 1;
	ph_4[2].dir = 2;
	ph_4[3].dir = 3;
	ph_4[4].dir = 4;
	if (mapp[ant[x].x][ant[x].y + 1].is_it_ant || mapp[ant[x].x][ant[x].y + 1].battery_or_not || ant[x].y >= m) ph_4[1].phh = false;
	if (mapp[ant[x].x + 1][ant[x].y].is_it_ant || mapp[ant[x].x + 1][ant[x].y].battery_or_not || ant[x].x >= n) ph_4[2].phh = false;
	if (mapp[ant[x].x][ant[x].y - 1].is_it_ant || mapp[ant[x].x][ant[x].y - 1].battery_or_not || ant[x].y <= 0) ph_4[3].phh = false;
	if (mapp[ant[x].x - 1][ant[x].y].is_it_ant || mapp[ant[x].x - 1][ant[x].y].battery_or_not || ant[x].x <= 0) ph_4[4].phh = false;
	int flag = 0;
	for (int i = 1; i <= 4; i++) {
		if (ph_4[i].phh) flag++;
	}
	if (flag > 1) {//如果有多个方向上没有障碍物 
		ph_4[1].ph = mapp[ant[x].x][ant[x].y + 1].pheromone;
		ph_4[2].ph = mapp[ant[x].x + 1][ant[x].y].pheromone;
		ph_4[3].ph = mapp[ant[x].x][ant[x].y - 1].pheromone;
		ph_4[4].ph = mapp[ant[x].x - 1][ant[x].y].pheromone;
		sort(ph_4 + 1, ph_4 + 4 + 1, choose_direction_cmp);
		if (ph_4[1].ph == ph_4[2].ph) {//如果有多个方向上的信息素相等
			for (int i = 1; i <= 4; i++) {
				
			} 
		}
		else {
			return ph_4[1].dir;
		}
	}
	else {
		for (int i = 1; i <= 4; i++) {
			if (ph_4[i].phh) return ph_4[i].dir;
		}
	}
}
void ans_go (int dir, int x) { //蚂蚁前进，参数：前进的方向 ；这是第几只蚂蚁 
	mapp[ant[x].x][ant[x].y].is_it_ant = false;
	switch (dir) {
		case 1:
			ant[x].y++;
			break;
		case 2:
			ant[x].x++;
			break;
		case 3:
			ant[x].y--;
			break;
		case 4:
			ant[x].x--;
			break;
	}
	mapp[ant[x].x][ant[x].y].is_it_ant = true;
	leave_pheromone (x);
}

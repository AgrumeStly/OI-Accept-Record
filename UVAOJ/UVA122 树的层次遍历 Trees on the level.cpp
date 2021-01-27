#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#define line cout << endl
using namespace std;


inline int read() {
    int f = 1, x = 0; char ch;
    do {
		ch = getchar();
		if (ch == '-') f = -1;
	} while (ch < '0' || ch > '9');
    do {
		x = x * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
    return f * x;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar (x % 10 + '0');
}

struct node {
	string val;
	node *left, *right;
	node () {
		left = right = NULL;
		val = "?";
	}
} *root;
string s;

bool check(node *now) {
	if (now->val == "?" || 
	now->left != NULL && !check(now->left) || 
	now->right != NULL && !check(now->right))
		return false;
	return true;
}

void bfs() {
	queue<node*> q;
	cout << root->val;
	q.push(root);
	while (!q.empty()) {
		node *now = q.front();
		q.pop();
		if (now->left != NULL) {
			cout << " " << now->left->val;
			q.push(now->left);
		}
		if (now->right != NULL) {
			cout << " " << now->right->val;
			q.push(now->right);
		}
	}
	return;
}

int main() {
	while (cin >> s) {
		root = new node;
		bool valid = true;
		while (s != "()") {
			node *now = root;
			for (int i = s.find(",") + 1; i < s.size() - 1; i++)
				if (s[i] == 'L') {
					if (now->left == NULL)
						now->left = new node;
					now = now->left;
				}
				else {
					if (now->right == NULL)
						now->right = new node;
					now = now->right;
				}
			if (now->val == "?") now->val = s.substr(1, s.find(",") - 1);
			else valid = false;
			cin >> s;
		}
		if (valid && check(root)) bfs();
		else cout << "not complete";
		puts("");
	}
	return 0;
}


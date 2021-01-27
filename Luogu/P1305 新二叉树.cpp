#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define line cout << endl
using namespace std;

struct node {
	char val;
	node *left, *right;
	node () {
		left = right = NULL;
	}
} *p[300], *root;

void dfs(node *x) {
	cout << x->val;
	if (x->left != NULL) dfs(x->left);
	if (x->right != NULL) dfs(x->right);
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 26; i++) {
		p[i] = new node;
		p[i]->val = 'a' + i - 1;
	}
	for (int i = 1; i <= n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (i == 1) {
			root = new node;
			root = p[a - 'a' + 1];
			root->val = a;
		}
		if (b != '*') {
			p[a - 'a' + 1]->left = p[b - 'a' + 1];
		}
		if (c != '*') {
			p[a - 'a' + 1]->right = p[c - 'a' + 1];
		}
	}
	dfs(root);
	return 0;
}


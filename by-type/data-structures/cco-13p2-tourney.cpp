#include <cstdio>
#include <cmath>
#include <iostream>
#define lchild 2 * idx
#define rchild 2 * idx + 1
using namespace std;

struct node {
	int l, r, max, orig;
} tree[4194305];

int n, m, c=1, pos[4194305];
char oper;

int s(int idx) {
	int elem = tree[pos[idx]].max, cnt = 0, curr=pos[idx];
	while (tree[curr/=2].max == elem) cnt++;
	return cnt--;
}

void push_up(int idx) {
	tree[idx].max = tree[lchild].max > tree[rchild].max ? tree[lchild].max : tree[rchild].max;
	tree[idx].orig = tree[lchild].max > tree[rchild].max ? tree[lchild].orig : tree[rchild].orig;
}

void build(int l, int r, int idx) {
	tree[idx].l = l, tree[idx].r = r;
	if (l == r)
	{
		cin >> tree[idx].max;
		pos[c] = idx;
		tree[idx].orig = c++;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lchild);
	build(mid + 1, r, rchild);
	push_up(idx);
}

// Update position x in tree (bin search)
void update(int x, int val, int idx) {
	if (tree[idx].l > x && tree[idx].r < x)
		return;
	// found
	if (tree[idx].l == tree[idx].r && tree[idx].l == x) {
		tree[idx].max = val;
		return;
	}
	int mid = (tree[idx].l + tree[idx].r) / 2;
	if (x <= mid) update(x, val, lchild);
	else update(x, val, rchild);
	push_up(idx);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int thing = 0, updateStep = 0;
	cin >> n >> m;
	build(1, pow(2, n), 1);
	for (int i = 0; i < m; i++) {
		cin >> oper;
		if (oper == 'R') {
			cin >> thing >> updateStep;
			update(thing, updateStep, 1);
		}
		else if (oper == 'W') {
			cout << tree[1].orig << '\n';
		}
		else {
			cin >> thing;
			cout << s(thing) << '\n';
		}
	}
	return 0;
}
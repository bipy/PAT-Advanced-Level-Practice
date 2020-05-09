#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;
struct node {
	int index, left, right;
	bool root = true;
};
vector<node> tree;
int s2i(string s) {
	return s == "-" ? -1 : stoi(s);
}
void check(int next) {
	if (next != -1) {
		tree[next].root = false;
	}
}
void showLevelOrder(int root) {
	deque<int> q;
	q.push_back(root);
	while (!q.empty()) {
		int cur = q.front();
		if (tree[cur].left != -1) {
			q.push_back(tree[cur].left);
		}
		if (tree[cur].right != -1) {
			q.push_back(tree[cur].right);
		}
		cur==root?printf("%d",cur):printf(" %d", cur);
		q.pop_front();
	}
	printf("\n");
}
void showInOrder(vector<int>& ans, int cur) {
	if (cur == -1) {
		return;
	}
	showInOrder(ans, tree[cur].left);
	ans.push_back(cur);
	showInOrder(ans, tree[cur].right);
}
int main() {
	int n;
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		string left, right;
		// 左右颠倒才对
		cin >> right >> left;
		tree[i] = node{ i,s2i(left),s2i(right) };
	}
	for (int i = 0; i < n; i++) {
		check(tree[i].left);
		check(tree[i].right);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (tree[i].root) {
			showLevelOrder(i);
			showInOrder(ans, i);
			break;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		i == 0 ? printf("%d", ans[i]) : printf(" %d", ans[i]);
	}
	return 0;
}
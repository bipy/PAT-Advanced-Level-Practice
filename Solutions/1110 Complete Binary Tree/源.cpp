#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
/*
判断完全二叉树思路：
层序遍历，判断两个条件：
1. 不能出现 左子树空，右子树非空
2. 第一个出现空子树的节点之后的所有节点必须为叶子节点
*/

struct node {
	int index, left, right;
};

vector<bool> rootList;
vector<node> tree;

int judge(string s) {
	if (s == "-") {
		return -1;
	}
	int rt = stoi(s);
	rootList[rt] = true;
	return rt;
}

int main() {
	int N, root, ans = 0;
	cin >> N;
	rootList.resize(N, false);
	tree.resize(N);
	string left, right;
	for (int i = 0; i < N; i++) {
		cin >> left >> right;
		if (left == "-" && right != "-") {
			ans = -1;
		}
		tree[i] = node{ i,judge(left),judge(right) };
	}
	for (int i = 0; i < rootList.size(); i++) {
		if (!rootList[i]) {
			root = i;
			break;
		}
	}
	if (ans != -1) {
		queue<node> q;
		q.push(tree[root]);
		bool leaf = false;
		while (!q.empty()) {
			node cur = q.front();
			if (leaf && (cur.right != -1 || cur.left != -1)) {
				ans = -1;
				break;
			}
			else if(cur.right == -1){
				leaf = true;
			}
			if (cur.left != -1) {
				q.push(tree[cur.left]);
			}
			if (cur.right != -1) {
				q.push(tree[cur.right]);
			}
			ans = cur.index;
			q.pop();
		}
	}
	if (ans == -1) {
		printf("NO %d", root);
	}
	else {
		printf("YES %d", ans);
	}
	return 0;
}
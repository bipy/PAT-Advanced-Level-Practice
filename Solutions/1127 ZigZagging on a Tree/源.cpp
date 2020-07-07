#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// 树节点
struct node {
	int val, depth = 0;
	node* left, * right;
};
// 中序，后序，答案
vector<int> in, post, ans;
// 用于层序遍历
deque<node*> q;
// 层序遍历中储存某一层序列
deque<int> temp;
// 树根
node* R = NULL;

// 读入数据
void init(int N, vector<int>& cur) {
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cur.emplace_back(temp);
	}
}

node* new_node(node* cur, int x, int depth) {
	if (!cur) {
		cur = new node();
	}
	cur->depth = depth;
	cur->val = x;
	return cur;
}
// 建树
// 实际为中后序转前序的过程，将当前节点加入树中
node* build_tree(node* cur, int root, int inL, int inR, int depth) {
	if (inL > inR) {
		return NULL;
	}
	int index = inL;
	cur = new_node(cur, post[root], depth);
	for (int i = inL; i <= inR; i++) {
		if (in[i] == post[root]) {
			index = i;
			break;
		}
	}
	cur->left = build_tree(cur->left, root - (inR - index) - 1, inL, index - 1, depth + 1);
	cur->right = build_tree(cur->right, root - 1, index + 1, inR, depth + 1);
	return cur;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;
	init(N, in);
	init(N, post);
	// 建树
	R = build_tree(R, N - 1, 0, N - 1, 0);
	// 层序遍历
	// cur_depth 记录当前深度
	int cur_depth = 0;
	q.emplace_back(R);
	while (!q.empty()) {
		node* cur = q.front();
		// 如果层数已经加深了，将缓冲区temp中的序列压入vector，清空缓存区
		if (cur->depth > cur_depth) {
			for (auto& it : temp) {
				ans.emplace_back(it);
			}
			cur_depth = cur->depth;
			temp.clear();
		}
		// 根据深度奇偶来决定顺序
		if (cur_depth % 2 != 0) {
			temp.emplace_back(cur->val);
		}
		else {
			temp.emplace_front(cur->val);
		}
		// BFS
		if (cur->left) {
			q.emplace_back(cur->left);
		}
		if (cur->right) {
			q.emplace_back(cur->right);
		}
		q.pop_front();
	}
	// BFS结束，将剩余序列压入vector
	for (auto& it : temp) {
		ans.emplace_back(it);
	}
	// 顺序输出
	for (int i = 0; i < ans.size(); i++) {
		printf(i == 0 ? "%d" : " %d", ans[i]);
	}
	return 0;
}
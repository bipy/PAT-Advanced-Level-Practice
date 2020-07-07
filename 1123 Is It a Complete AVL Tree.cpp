#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
struct node {
	int val, h;
	node* left, * right;
};
node* root = NULL;

int get_height(node* cur) {
	return cur ? cur->h : 0;
}

void re_height(node* cur) {
	cur->h = max(get_height(cur->right), get_height(cur->left)) + 1;
}

node* new_node(int x) {
	node* rt = new node();
	rt->val = x;
	rt->h = 0;
	return rt;
}

node* left_left_rotation(node* cur) {
	node* p = cur->left;
	cur->left = p->right;
	p->right = cur;
	re_height(cur);
	re_height(p);
	return p;
}

node* right_right_rotation(node* cur) {
	node* p = cur->right;
	cur->right = p->left;
	p->left = cur;
	re_height(cur);
	re_height(p);
	return p;
}

node* left_right_rotation(node* cur) {
	cur->left = right_right_rotation(cur->left);
	return left_left_rotation(cur);
}

node* right_left_rotation(node* cur) {
	cur->right = left_left_rotation(cur->right);
	return right_right_rotation(cur);
}

node* insert(node* cur, int x) {
	if (!cur) {
		cur = new_node(x);
	}
	else if (x > cur->val) {
		cur->right = insert(cur->right, x);
		if (get_height(cur->left) - get_height(cur->right) == -2) {
			if (cur->right->val < x) {
				cur = right_right_rotation(cur);
			}
			else {
				cur = right_left_rotation(cur);
			}
		}
	}
	else if (x < cur->val) {
		cur->left = insert(cur->left, x);
		if (get_height(cur->left) - get_height(cur->right) == 2) {
			if (cur->left->val > x) {
				cur = left_left_rotation(cur);
			}
			else {
				cur = left_right_rotation(cur);
			}
		}
	}
	re_height(cur);
	return cur;
}

int main() {
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		root = insert(root, temp);
	}
	// 检查是否为完全二叉树
	bool flag = false, isCBT = true;
	deque<node*> q;
	vector<int> ans;
	q.emplace_back(root);
	while (!q.empty()) {
		node* cur = q.front();
		// 只有左子树为空的情况
		if (!cur->left && cur->right) {
			isCBT = false;
		}
		if (cur->left) {
			q.emplace_back(cur->left);
			// 末尾节点有左子树，则不是完全树
			if (flag) {
				isCBT = false;
			}
		}
		if (cur->right) {
			q.emplace_back(cur->right);
		}
		else {
			// 右子树为空，则开始判断末尾节点
			flag = true;
		}
		ans.emplace_back(cur->val);
		q.pop_front();
	}
	for (int i = 0; i < ans.size(); i++) {
		printf(i == 0 ? "%d" : " %d", ans[i]);
	}
	printf(isCBT ? "\nYES" : "\nNO");
	return 0;
}
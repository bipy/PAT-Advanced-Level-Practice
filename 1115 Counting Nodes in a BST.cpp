#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstdlib>
using namespace std;
typedef struct node *ptr;
// 树结点
struct node {
	int val, depth = 0;
	ptr left, right;
};
// 建树
ptr insert(ptr cur, int x, int depth) {
	if (!cur) {
		cur = new node();
		cur->val = x;
		cur->depth = depth;
		return cur;
	}
	if (x > cur->val) {
		cur->right = insert(cur->right, x, depth + 1);
	}
	else {
		cur->left = insert(cur->left, x, depth + 1);
	}
	return cur;
}
int main() {
	int N, temp;
	cin >> N;
	ptr root = new node();
	scanf("%d", &root->val);
	for (int i = 1; i < N; i++) {
		scanf("%d", &temp);
		insert(root, temp, 0);
	}
	// 层序遍历，记录最大层数
	int maxDepth = 0;
	unordered_map<int, int> count;
	queue<ptr> q;
	q.push(root);
	while (!q.empty()) {
		ptr cur = q.front();
		if (count.find(cur->depth) != count.end()) {
			count[cur->depth]++;
		}
		else {
			maxDepth = cur->depth;
			count[cur->depth] = 1;
		}
		if (cur->right) {
			q.push(cur->right);
		}
		if (cur->left) {
			q.push(cur->left);
		}
		q.pop();
	}
	printf("%d + %d = %d", count[maxDepth], count[maxDepth - 1], count[maxDepth] + count[maxDepth - 1]);
	return 0;
}
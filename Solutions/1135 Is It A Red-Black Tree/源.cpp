#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef struct node* Tree;
struct node {
	int value;
	Tree left, right;
};
unordered_map<int, bool> rb;
Tree NewNode(int x) {
	Tree T = new node;
	T->left = NULL;
	T->right = NULL;
	T->value = x;
	return T;
}
Tree Insert(Tree T, int x) {
	if (!T) {
		return NewNode(x);
	}
	if (T->value >= x) {
		T->left = Insert(T->left, x);
	}
	else {
		T->right = Insert(T->right, x);
	}
	return T;
}
void check(Tree T, unordered_set<int>& ans, int count, bool& isrbtree) {
	if (T == NULL) {
		ans.insert(count);
		return;
	}
	if (T->left != NULL && !rb[T->value] && rb[T->value] == rb[T->left->value]) {
		isrbtree = false;
		return;
	}
	if (T->right != NULL && !rb[T->value] && rb[T->value] == rb[T->right->value]) {
		isrbtree = false;
		return;
	}
	if (rb[T->value]) {
		count++;
	}
	check(T->left, ans, count, isrbtree);
	check(T->right, ans, count, isrbtree);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, temp;
		scanf("%d", &num);
		vector<int> pre(num);
		rb.clear();
		Tree T = NULL;
		for (int j = 0; j < num; j++) {
			scanf("%d", &temp);
			rb[fabs(temp)] = temp > 0;
			pre[j] = fabs(temp);
			T = Insert(T, pre[j]);
		}
		bool isrbtree = true;
		if (!rb[pre[0]]) {
			isrbtree = false;
		}
		else {
			unordered_set<int> ans;
			check(T, ans, 0, isrbtree);
			if (ans.size() != 1) {
				isrbtree = false;
			}
		}
		isrbtree ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
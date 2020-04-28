#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int val = -1;
	int left, right;
};
vector<node> tree;
vector<int> seq, ans;
// ±È¿˙∏≥÷µ
void travel(int cur) {
	if (tree[cur].right != -1) {
		travel(tree[cur].right);
	}
	tree[cur].val = seq.back();
	seq.pop_back();
	if (tree[cur].left != -1) {
		travel(tree[cur].left);
	}
}
int main() {
	int n;
	cin >> n;
	seq.resize(n);
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.left >> temp.right;
		tree.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	travel(0);
	// ≤„–Ú±È¿˙
	ans.push_back(0);
	int p = 0;
	while (ans.size() < n) {
		int index = ans[p];
		if (tree[index].left != -1) {
			ans.push_back(tree[index].left);
		}
		if (tree[index].right != -1) {
			ans.push_back(tree[index].right);
		}
		p++;
	}
	for (int i = 0; i < ans.size(); i++) {
		i == 0 ? printf("%d", tree[ans[i]].val) : printf(" %d", tree[ans[i]].val);
	}
	return 0;
}
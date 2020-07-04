#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node {
	string data;
	int left = -1, right = -1, parent = -1;
};
vector<node> ans;
string output;
void dfs(int cur) {
	if (ans[cur].left != -1 || ans[cur].right != -1) {
		output += "(";
	}
	if (ans[cur].left != -1) {
		dfs(ans[cur].left);
	}
	output += ans[cur].data;
	if (ans[cur].right != -1) {
		dfs(ans[cur].right);
	}
	if (ans[cur].left != -1 || ans[cur].right != -1) {
		output += ")";
	}
}
int main() {
	int n, root;
	cin >> n;
	ans.push_back(node{});
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.data >> temp.left >> temp.right;
		ans.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i].left != -1) {
			ans[ans[i].left].parent = i;
		}
		if (ans[i].right != -1) {
			ans[ans[i].right].parent = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i].parent == -1) {
			root = i;
			break;
		}
	}
	dfs(root);
	cout << (n == 1 ? output : output.substr(1, output.length() - 2));
	return 0;
}
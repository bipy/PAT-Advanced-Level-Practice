#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int weight;
	vector<int> child;
};
int n, m, k;
vector<node> tree;
vector<vector<int> > ans;
bool cmp(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size() && i < b.size(); i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
	return a[0] > b[0];
}
void process(vector<int> temp, int sum, int cur) {
	if (sum == k && tree[cur].child.empty()) {
		ans.push_back(temp);
		return;
	}
	if (sum >= k) {
		return;
	}
	for (auto it = tree[cur].child.begin(); it != tree[cur].child.end(); it++) {
		vector<int> next = temp;
		next.push_back(tree[*it].weight);
		process(next, sum + tree[*it].weight, *it);
	}
}
int main() {
	cin >> n >> m >> k;
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i].weight;
	}
	for (int i = 0; i < m; i++) {
		int index, num;
		cin >> index >> num;
		tree[index].child.resize(num);
		for (int j = 0; j < num; j++) {
			cin >> tree[index].child[j];
		}
	}
	vector<int> temp;
	temp.push_back(tree[0].weight);
	process(temp, tree[0].weight, 0);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			j == ans[i].size() - 1 ? printf("%d\n", ans[i][j]) : printf("%d ", ans[i][j]);
		}
	}
	return 0;
}
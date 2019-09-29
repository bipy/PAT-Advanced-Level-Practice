#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int index, value;
};
vector<int> post, in;
vector<node> ans;
bool cmp(node a, node b) {
	return a.index < b.index;
}
void pre(int root, int start, int end, int index) {
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	ans.push_back(node{ index,post[root] });
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
	pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		post.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		in.push_back(t);
	}
	pre(n - 1, 0, n - 1, 0);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < n; i++) {
		i == n - 1 ? printf("%d", ans[i].value) : printf("%d ", ans[i].value);
	}
	return 0;
}
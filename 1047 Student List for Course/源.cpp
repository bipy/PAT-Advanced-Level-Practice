#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
	char id[5];
};
bool cmp(node a,node b) {
	return strcmp(a.id, b.id) < 0;
}
vector<vector<node> > ans;
int main() {
	int n, m, c, t;
	cin >> n >> m;
	ans.resize(m + 1);
	for (int i = 0; i < n; i++) {
		node temp;
		scanf("%s %d", temp.id, &c);
		for (int i = 0; i < c; i++) {
			cin >> t;
			ans[t].push_back(temp);
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d %d\n", i, ans[i].size());
		sort(ans[i].begin(), ans[i].end(),cmp);
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%s\n", ans[i][j].id);
		}
	}
	return 0;
}
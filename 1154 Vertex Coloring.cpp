#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
vector<vector<int> > g;
int main() {
	int n, m,k;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> color(n);
		unordered_set<int> count;
		for (int j = 0; j < n; j++) {
			scanf("%d", &color[j]);
			count.insert(color[j]);
		}
		bool proper = true;
		for (int j = 0; j < n; j++) {
			for (int u = 0; u < g[j].size(); u++) {
				if (color[g[j][u]] == color[j]) {
					proper = false;
					break;
				}
			}
			if (!proper) {
				break;
			}
		}
		if (proper) {
			printf("%d-coloring\n", count.size());
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
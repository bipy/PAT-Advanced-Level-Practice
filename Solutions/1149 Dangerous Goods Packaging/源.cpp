#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstdlib>
using namespace std;
unordered_map<int, vector<int> > g;
int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		bool check[100000];
		fill(check, check + 100000, true);
		int* seq = new int[t];
		bool flag = false;
		for (int j = 0; j < t; j++) {
			scanf("%d", &seq[j]);
			for (auto it = g[seq[j]].begin(); it != g[seq[j]].end(); it++) {
				check[*it] = false;
			}
		}
		for (int j = 0; j < t; j++) {
			if (check[seq[j]] == false) {
				printf("No\n");
				flag = true;
				break;
			}
		}
		if (!flag) {
			printf("Yes\n");
		}
	}
	return 0;
}
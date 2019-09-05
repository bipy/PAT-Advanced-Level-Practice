#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> pre;
unordered_map<int, bool> exist;
int main() {
	int m, n, u, v;
	cin >> m >> n;
	pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &pre[i]);
		exist[pre[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		if (!exist[u] && !exist[v]) {
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else if (!exist[u] || !exist[v]) {
			printf("ERROR: %d is not found.\n", exist[u] ? v : u);
		}
		else {
			for (int i = 1; i < pre.size(); i++) {
				if (u < pre[i] && v > pre[i] || u > pre[i] && v < pre[i]) {
					printf("LCA of %d and %d is %d.\n", u, v, pre[i]);
					break;
				}
				else if (u == pre[i] || v == pre[i]) {
					printf("%d is an ancestor of %d.\n", pre[i], u == pre[i] ? v : u);
					break;
				}
			}
		}
	}
	return 0;
}
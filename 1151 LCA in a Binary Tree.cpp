#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, int> pos;
vector<int> in, pre;
void lca(int left, int right, int preRoot, int a, int b) {
	if (left > right) {
		return;
	}
	int inRoot = pos[pre[preRoot]], pa = pos[a], pb = pos[b];
	if (pa < inRoot && pb < inRoot) {
		lca(left, inRoot - 1, preRoot + 1, a, b);
	}
	else if (pa<inRoot && pb>inRoot || pa > inRoot && pb < inRoot) {
		printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
	}
	else if (pa == inRoot || pb == inRoot) {
		printf("%d is an ancestor of %d.\n", pa == inRoot ? a : b, pa == inRoot ? b : a);
	}
	else if (pa > inRoot && pb > inRoot) {
		lca(inRoot + 1, right, preRoot + inRoot - left + 1, a, b);
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	in.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
		pos[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ea = pos.count(a), eb = pos.count(b);
		if (ea == 0 && eb == 0) {
			printf("ERROR: %d and %d are not found.\n", a, b);
		}
		else if (ea == 0 || eb == 0) {
			printf("ERROR: %d is not found.\n", ea == 0 ? a : b);
		}
		else {
			lca(1, n, 1, a, b);
		}
	}
	return 0;
}
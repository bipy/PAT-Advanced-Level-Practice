#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	int index, depth = -1;
};
vector<vector<int> > supMap;
vector<node> ans;
int maxD = -1;
void dfs(int cur, int depth) {
	bool leaf = true;
	if (depth > maxD) {
		maxD = depth;
	}
	for (auto it = supMap[cur].begin(); it != supMap[cur].end(); it++) {
		dfs(*it, depth + 1);
		leaf = false;
	}
	if (leaf) {
		ans.push_back(node{ cur,depth });
	}
}
int main() {
	int n, root = 0;
	double p, r;
	cin >> n >> p >> r;
	supMap.resize(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == -1) {
			root = i;
		}
		else {
			supMap[temp].push_back(i);
		}
	}
	dfs(root, 0);
	int count = 0;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (it->depth == maxD) {
			count++;
		}
	}
	printf("%.2f %d", p * pow(1 + 0.01 * r, maxD), count);

	return 0;
}
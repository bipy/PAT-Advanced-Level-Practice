#include<iostream>
#include<vector>
using namespace std;
struct node {
	int index, level;
};
vector<vector<int> > family;
vector<bool> visited;//防止乱伦
vector<int> gen;
void dfs(node cur) {
	visited[cur.index] = true;
	gen[cur.level]++;
	for (auto it = family[cur.index].begin(); it != family[cur.index].end(); it++) {
		if (!visited[*it]) {
			dfs(node{ *it,cur.level + 1 });
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	family.resize(n + 1);
	visited.resize(n + 1, false);
	gen.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int index, num;
		cin >> index >> num;
		for (int j = 0; j < num; j++) {
			int next;
			cin >> next;
			family[index].push_back(next);
		}
	}
	dfs(node{ 1,1 });
	int max = -1;
	for (int i = 1; i < gen.size(); i++) {
		if (gen[i] > max) {
			max = gen[i];
		}
	}
	for (int i = 1; i < gen.size(); i++) {
		if (gen[i] == max) {
			cout << max << " " << i;
			break;
		}
	}
	return 0;
}
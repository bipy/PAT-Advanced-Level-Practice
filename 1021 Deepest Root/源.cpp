#include<iostream>
#include<vector>
#include<set>
#define maxN 10010
using namespace std;
bool visited[maxN];
set<int> ans;
int  n, height[maxN] = { 0 };
vector<int> g[maxN];
void DFS(int v) {
	visited[v] = true;
	for (int i : g[v]) {
		if (visited[i] == false) {
			height[i] = height[v] + 1;
			DFS(i);
		}
	}
}
void process() {
	int max = 1;
	for (int i = 1; i <= n; i++) {
		if (height[max] < height[i]) {
			max = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (height[max] == height[i]) {
			ans.insert(i);
		}
	}
}
int main() {
	cin >> n;
	fill(visited, visited + maxN, false);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			DFS(i);
			count++;
		}
	}
	if (count > 1) {
		printf("Error: %d components", count);
	}
	else {
		process();
		fill(visited, visited + maxN, false);
		fill(height, height + maxN, 0);
		auto it = ans.begin();
		DFS(*it);
		process();
		for (auto it = ans.begin(); it != ans.end(); it++) {
			cout << *it << endl;
		}
	}
	return 0;
}
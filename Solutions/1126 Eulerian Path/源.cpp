#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > m;
vector<bool> visited;
int vertex_count = 0;
void dfs(int cur) {
	visited[cur] = true;
	vertex_count++;
	for (auto& it : m[cur]) {
		if (!visited[it]) {
			dfs(it);
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	int N, M, a, b, odd_count = -999;
	cin >> N >> M;
	m.resize(N + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		m[a].emplace_back(b);
		m[b].emplace_back(a);
	}
	visited.resize(N + 1, false);
	// 判断是否连通
	dfs(1);
	if (vertex_count == N) {
		odd_count = 0;
	}
	for (int i = 1; i <= N; i++) {
		int size = m[i].size();
		printf(i == 1 ? "%d" : " %d", size);
		if (size % 2 != 0) {
			odd_count++;
		}
	}
	if (odd_count == 0) {
		printf("\nEulerian");
	}
	else if (odd_count == 2) {
		printf("\nSemi-Eulerian");
	}
	else {
		printf("\nNon-Eulerian");
	}
	return 0;
}
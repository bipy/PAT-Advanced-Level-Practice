#include<iostream>
#include<vector>
#include<deque>
using namespace std;
struct node {
	int id, level;
};
int N, L, K;
vector<vector<int> > v;
int main() {
	cin >> N >> L;
	v.resize(N+1);
	for (int i = 1; i <= N; i++) {
		int amount, followed;
		scanf("%d", &amount);
		for (int j = 0; j < amount; j++) {
			scanf("%d", &followed);
			v[followed].push_back(i);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		bool* visited = (bool*)malloc(sizeof(bool) * (N + 1));
		fill(visited, visited + N + 1, false);
		deque<node> q;
		int start, count = 0;
		scanf("%d", &start);
		q.push_back(node{ start,0 });
		visited[start] = true;
		while (!q.empty()) {
			node cur = q.front();
			for (auto it = v[cur.id].begin(); it != v[cur.id].end(); it++) {
				if (!visited[*it]) {
					visited[*it] = true;
					count++;
					if (cur.level + 1 < L) {
						q.push_back(node{ *it,cur.level + 1 });
					}
				}
			}
			q.pop_front();
		}
		printf("%d\n", count);
	}
	return 0;
}
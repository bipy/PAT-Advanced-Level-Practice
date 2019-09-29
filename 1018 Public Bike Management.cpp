#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define maxN 501
#define INF 99999
using namespace std;
struct HeapNode {
	int d, u;
	bool operator < (const HeapNode& rhs) const {
		return d > rhs.d;
	}
};
int c, n, sp, m, g[maxN][maxN], dis[maxN], bike[maxN], visited[maxN] = { 0 };
vector<vector<int> > path;
vector<int> temp;
void getpath(int cur, vector<int> temp) {
	for (int i = 0; i <= n; i++) {
		vector<int> copy = temp;
		if (visited[i] == 0 && g[i][cur] != -1 && dis[cur] == dis[i] + g[i][cur]) {
			if (i == 0) {
				path.push_back(temp);
				return;
			}
			copy.push_back(i);
			getpath(i, copy);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	priority_queue<HeapNode> pq;
	fill(g[0], g[0] + maxN * maxN, -1);
	fill(dis, dis + maxN, INF);
	scanf("%d %d %d %d", &c, &n, &sp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &bike[i]);
	}
	for (int i = 0; i < m; i++) {
		int s1, s2, d;
		scanf("%d %d %d", &s1, &s2, &d);
		g[s1][s2] = g[s2][s1] = d;
	}
	dis[0] = 0;
	for (int i = 0; i <= n; i++) {
		int cur = -1, min = INF;
		pq.push(HeapNode{ 0,0 });
		while (!pq.empty()) {
			HeapNode x = pq.top();
			pq.pop();
			int cur = x.u;
			if (visited[cur] == 0) {
				visited[cur] = 1;
				for (int j = 0; j <= n; j++) {
					if (g[cur][j] != -1 && dis[j] > dis[cur] + g[cur][j]) {
						dis[j] = dis[cur] + g[cur][j];
						pq.push(HeapNode{ dis[j],j });
					}
				}
			}
		}
		/*	for (int j = 0; j <= n; j++) {
				if (min > dis[j] && visited[j] == 0) {
					min = dis[j];
					cur = j;
				}
			}
			if (cur == -1) {
				break;
			}

			visited[cur] = 1;
			for (int k = 1; k <= n; k++) {
				if (g[cur][k] != -1 && visited[k] == 0) {
					if (dis[k] > dis[cur] + g[cur][k]) {
						dis[k] = dis[cur] + g[cur][k];
					}
				}
			}*/
	}
	fill(visited, visited + maxN, 0);
	temp.push_back(sp);
	getpath(sp, temp);
	vector<int> ans;
	int min = INF, send = INF;
	for (auto it = path.begin(); it != path.end(); it++) {
		int have = 0, cost = 0;
		for (int i = it->size() - 1; i >= 0; i--) {
			have += bike[(*it)[i]] - c / 2;
			if (have < 0) {
				cost -= have;
				have = 0;
			}
		}
		if (send > cost) {
			send = cost;
			min = have;
			ans = *it;
		}
		else if (send == cost && min > have) {
			min = have;
			ans = *it;
		}
	}
	printf("%d 0", send);
	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		printf("->%d", *it);
	}
	printf(" %d", min);
	return 0;
}
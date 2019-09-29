#include<iostream>
#include<vector>
#define INF 9999999
#define maxN 501
using namespace std;
int edge[maxN][maxN], dis[maxN], visited[maxN], cost[maxN][maxN], total[maxN];
int n, m, s, d;
vector<int> ans;
void process(int v) {
	visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && dis[v] == edge[i][v] + dis[i] && total[v] == total[i] + cost[i][v]) {
			ans.push_back(v);
			process(i);
		}
	}
}
int main() {
	cin >> n >> m >> s >> d;
	fill(edge[0], edge[0] + maxN * maxN, -1);
	fill(cost[0], cost[0] + maxN * maxN, -1);
	for (int i = 0; i < m; i++) {
		int c1, c2, tdis, tcost;
		cin >> c1 >> c2 >> tdis >> tcost;
		edge[c1][c2] = edge[c2][c1] = tdis;
		cost[c1][c2] = cost[c2][c1] = tcost;
	}
	fill(visited, visited + maxN, 0);
	fill(dis, dis + maxN, INF);
	fill(total, total + maxN, INF);
	dis[s] = 0;
	total[s] = 0;
	for (int i = 0; i < n; i++) {
		int cur = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == 0 && dis[j] < min) {
				cur = j;
				min = dis[j];
			}
		}
		if (cur == -1) {
			break;
		}
		visited[cur] = 1;
		for (int k = 0; k < n; k++) {
			if (visited[k] == 0 && edge[cur][k] != -1) {
				if (dis[k] > dis[cur] + edge[cur][k]) {
					dis[k] = dis[cur] + edge[cur][k];
					total[k] = total[cur] + cost[cur][k];
				}
				else if (dis[k] == dis[cur] + edge[cur][k] && total[k] > total[cur] + cost[cur][k]) {
					total[k] = total[cur] + cost[cur][k];
				}
			}
		}
	}
	fill(visited, visited + maxN, 0);
	process(d);
	ans.push_back(s);
	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		printf("%d ", *it);
	}
	printf("%d %d", dis[d], total[d]);
	return 0;
}
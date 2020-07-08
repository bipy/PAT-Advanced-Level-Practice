#include<iostream>
#include<algorithm>
#define maxNum 510
#define INF 999999
using namespace std;
int N, M, C1, C2;
int edge[maxNum][maxNum], num[maxNum], man[maxNum], dis[maxNum], gather[maxNum];
//num 到i点最短路径条数
//man 城市里人数
//gather 到第i点已集结人数之和
bool visited[maxNum];
int main() {
	freopen("Text.txt", "r", stdin);
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++) {
		cin >> man[i];
	}
	fill(edge[0], edge[0] + maxNum * maxNum, INF);
	fill(dis, dis + maxNum, INF);
	for (int i = 0; i < M; i++) {
		int c1, c2, L;
		cin >> c1 >> c2 >> L;
		edge[c1][c2] = edge[c2][c1] = L;
	}
	dis[C1] = 0;
	gather[C1] = man[C1];
	num[C1] = 1;
	for (int i = 0; i < N; i++) {
		int cur = -1, min = INF;
		for (int j = 0; j < N; j++) {
			if (visited[j] == false && dis[j] < min) {
				min = dis[j];
				cur = j;
			}
		}
		if (cur == -1) {
			break;
		}
		visited[cur] = true;
		for (int k = 0; k < N; k++) {
			if (visited[k] == false && edge[cur][k] != INF) {
				if (dis[cur] + edge[cur][k] < dis[k]) {
					dis[k] = dis[cur] + edge[cur][k];
					num[k] = num[cur];
					gather[k] = gather[cur] + man[k];
				}
				else if (dis[cur] + edge[cur][k] == dis[k]) {
					num[k] = num[k] + num[cur];
					if (gather[cur] + man[k] > gather[k]) {
						gather[k] = gather[cur] + man[k];
					}
				}
			}
		}
	}
	cout << num[C2] << " " << gather[C2] << endl;
	return 0;
}

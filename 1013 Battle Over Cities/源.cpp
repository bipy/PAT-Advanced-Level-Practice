#include<iostream>
#include<vector>
#define maxN 1001
/*
	有一定概率超时，把cin换成scanf后可节省4ms
*/
using namespace std;
int N, K, M, concern;
int g[maxN][maxN], connected[maxN] = { 0 };
void count(int t, int* visited) {
	visited[t] = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1 && g[t][i] == 1) {
			count(i, visited);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	fill(g[0], g[0] + maxN * maxN, -1);
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		g[c1][c2] = g[c2][c1] = 1;
	}
	for (int i = 0; i < K; i++) {
		int visited[maxN] = { 0 };
		scanf("%d", &concern);
		for (int j = 1; j <= N; j++) {
			if (g[concern][j] == 1) {
				g[j][concern] = g[concern][j] = 0;
			}
		}
		for (int j = 1; j <= N; j++) {
			if (visited[j] != 1 && j != concern) {
				count(j, visited);
				connected[concern]++;
			}
		}
		printf("%d\n", connected[concern] - 1);
		for (int j = 1; j <= N; j++) {
			if (g[concern][j] == 0) {
				g[j][concern] = g[concern][j] = 1;
			}
		}
	}
	return 0;
}
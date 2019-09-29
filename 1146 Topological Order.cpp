#include<iostream>
//#include<cstdlib>
#define maxN 1010
using namespace std;
int g[maxN][maxN], indegree[maxN], temp[maxN];
int main() {
	freopen("Text.txt", "r", stdin);
	int n, m, k, flag = 1;
	cin >> n >> m;
	//fill(g[0], g[0] + maxN * maxN, 0);
	//fill(indegree, indegree + maxN, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
		indegree[b]++;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int* query = new int[n];
		for (int j = 1; j <= n; j++) {
			temp[j] = indegree[j];
			scanf("%d", &query[j - 1]);
		}
		for (int j = 0; j < n; j++) {
			int t = query[j];
			if (temp[t] != 0) {
				flag == 1 ? flag = 0 : printf(" ", i);
				printf("%d", i);
				break;
			}
			for (int v = 1; v <= n; v++) {
				if (g[t][v] != 0) {
					temp[v]--;
				}
			}
		}
	}
	return 0;
}
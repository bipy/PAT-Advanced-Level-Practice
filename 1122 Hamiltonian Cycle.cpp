#include<iostream>
#include<vector>
using namespace std;
int main() {
	//freopen("Text.txt", "r", stdin);
	int N, M, a, b, K, n;
	cin >> N >> M;
	vector<vector<int> > matrix(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		bool flag = true;
		scanf("%d", &n);
		vector<int> curPath(n), visited(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &curPath[j]);
		}
		// 判断是否一个环
		if (curPath.front() != curPath.back() || n != N + 1) {
			printf("NO\n");
			continue;
		}
		// 判断节点间是否连通
		for (int k = 1; k < n; k++) {
			if (matrix[curPath[k - 1]][curPath[k]] == 0) {
				flag = false;
				break;
			}
			visited[curPath[k]] = 1;
		}
		// 判断是否访问了所有节点
		for (int l = 1; l < visited.size(); l++) {
			if (visited[l] == 0) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
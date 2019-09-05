#include<iostream>
#include<vector>
#include<unordered_set>
#define maxN 210
using namespace std;
int g[maxN][maxN];
int main() {
	int n, m, k, num;
	cin >> n >> m;
	fill(g[0], g[0] + maxN * maxN, -1);
	for (int i = 0; i < m; i++) {
		int c1, c2, dist;
		scanf("%d%d%d", &c1, &c2, &dist);
		g[c1][c2] = g[c2][c1] = dist;
	}
	cin >> k;
	int mindex, min = 999999;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &num);
		vector<int> seq(num);
		unordered_set<int> s;
		bool isfinished = false;
		for (int j = 0; j < num; j++) {
			scanf("%d", &seq[j]);
			s.insert(seq[j]);
		}
		printf("Path %d: ", i);
		int start = seq[0], end = seq.back(), total = 0;
		for (int j = 1; j < num; j++) {
			if (g[seq[j - 1]][seq[j]] == -1) {
				printf("NA (Not a TS cycle)\n", i);
				isfinished = true;
				break;
			}
			total += g[seq[j - 1]][seq[j]];
		}
		if (!isfinished) {
			printf("%d ", total);
			if (start != end || s.size() != n) {
				printf("(Not a TS cycle)\n");
			}
			else {
				if (min > total) {
					min = total;
					mindex = i;
				}
				if (num > n + 1) {
					printf("(TS cycle)\n");
				}
				else {
					printf("(TS simple cycle)\n");
				}
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", mindex, min);
	return 0;
}
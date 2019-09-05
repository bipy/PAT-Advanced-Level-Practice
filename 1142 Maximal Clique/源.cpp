#include<iostream>
#include<vector>
#define maxNv 205
using namespace std;
bool g[maxNv][maxNv];
int main() {
	int nv, ne, m;
	cin >> nv >> ne;
	fill(g[0], g[0] + maxNv * maxNv, false);
	for (int i = 0; i < ne; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		vector<int> seq;
		cin >> num;
		seq.resize(num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &seq[j]);
		}
		bool clique = true;
		for (int j = 0; j < num - 1; j++) {
			for (int k = j + 1; k < num; k++) {
				if (!g[seq[j]][seq[k]]) {
					clique = false;
					break;
				}
			}
			if (!clique) {
				break;
			}
		}
		if (!clique) {
			printf("Not a Clique\n");
		}
		else {
			bool maximal = true;
			for (int cur = 1; cur <= nv; cur++) {
				bool insert = true;
				for (int j = 0; j < num; j++) {
					if (!g[cur][seq[j]] || cur == seq[j]) {
						insert = false;
						break;
					}
				}
				if (insert) {
					maximal = false;
					break;
				}
			}
			if (maximal) {
				printf("Yes\n");
			}
			else {
				printf("Not Maximal\n");
			}
		}
	}
	return 0;
}
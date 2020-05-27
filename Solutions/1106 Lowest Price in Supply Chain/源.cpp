#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ROOT 0
using namespace std;
struct node {
	int index, depth;
};
vector<vector<node> > tree;
queue<node> q;
int main() {
	int N;
	double P, r;
	cin >> N >> P >> r;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int temp;
			scanf("%d", &temp);
			tree[i].push_back(node{ temp,0 });
		}
	}
	q.push(node{ ROOT,0 });
	int minDepth = INT32_MAX;
	int count = 0;
	while (!q.empty()) {
		node cur = q.front();
		if (cur.depth > minDepth) {
			break;
		}
		if (tree[cur.index].empty() && minDepth >= cur.depth) {
			count++;
			minDepth = cur.depth;
		}
		for (auto it = tree[cur.index].begin(); it != tree[cur.index].end(); it++) {
			it->depth = cur.depth + 1;
			q.push(*it);
		}
		q.pop();
	}
	printf("%.4f %d", P * pow(1 + r / 100, minDepth), count);
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
// 兴趣数量最大值
#define maxK 1001
using namespace std;
vector<vector<int> > v;
int main() {
	int N;
	cin >> N;
	// 并查集
	vector<int> pSet(N + 1, -1);
	v.resize(maxK);
	// 把人按兴趣分类
	for (int i = 1; i <= N; i++) {
		int K, temp;
		scanf("%d:", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &temp);
			v[temp].push_back(i);
		}
	}
	// 对于每个兴趣中的人进行操作
	for (auto it = v.begin() + 1; it != v.end(); it++) {
		if (it->size() > 1) {
			int root = it->at(0);
			while (pSet[root] > 0) {
				root = pSet[root];
			}
			for (int i = 1; i < it->size(); i++) {
				int curRoot = it->at(i);
				while (pSet[curRoot] > 0) {
					curRoot = pSet[curRoot];
				}
				pSet[root] += pSet[curRoot];
				pSet[curRoot] = root;
			}
		}
	}
	// 整理输出
	vector<int> ans;
	for (auto it = pSet.begin() + 1; it != pSet.end(); it++) {
		if (*it < 0) {
			ans.push_back(abs(*it));
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i > 0; i--) {
		printf("%d ", ans[i]);
	}
	printf("%d", ans[0]);
	return 0;
}
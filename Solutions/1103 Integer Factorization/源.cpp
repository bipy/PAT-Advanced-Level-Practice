#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	// 储存候选答案
	vector<int> v;
	// 数字总和
	int sum;
};
int N, K, P;
vector<node> ans;
vector<int> power;

bool cmp(const node& a, const node& b) {
	return a.sum > b.sum;
}

void dfs(int cur, int remain, node& n) {
	// 剪枝
	if (n.v.size() == K) {
		if (remain == 0) {
			ans.push_back(n);
		}
		return;
	}
	// 定上限，由大到小递归
	for (int i = cur; i >= 1; i--) {
		int next = remain - power[i];
		if (next >= 0) {
			n.v.push_back(i);
			dfs(i, next, n);
			n.v.pop_back();
		}
	}
}
int main() {
	cin >> N >> K >> P;
	// 打表避免重复计算
	power.resize((int)pow(N,1.0/P) + 1);
	for (int i = power.size() - 1; i > 0; i--) {
		power[i] = pow(i, P);
	}
	// 从 P次根 深度优先搜索
	node n;
	dfs((int)pow(N, 1.0 / P), N, n);
	// 格式化输出
	if (ans.size() == 0) {
		printf("Impossible");
	}
	else {
		// 计算总和并排序
		for (auto it = ans.begin(); it != ans.end(); it++) {
			int sum = 0;
			for (int i = 0; i < it->v.size(); i++) {
				sum += it->v[i];	
			}
			it->sum = sum;
		}
		sort(ans.begin(), ans.end(), cmp);
		// 总和相同，找最大的数组（测试点2）
		int max = 0;
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i].sum < ans[i - 1].sum) {
				break;
			}
			for (int j = 0; j < K; j++) {
				if (ans[i].v[j] > ans[max].v[j]) {
					max = i;
					break;
				}
			}
		}
		printf("%d = ", N);
		for (int i = 0; i < K; i++) {
			i == 0 ? printf("%d^%d", ans[max].v[i], P) : printf(" + %d^%d", ans[max].v[i], P);
		}
	}
	return 0;
}

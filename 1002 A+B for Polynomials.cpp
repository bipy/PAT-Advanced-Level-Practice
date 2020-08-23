#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int e;
	double c;
};
// map 解决数组内存浪费问题
unordered_map<int, double> m;

bool cmp(const node& a, const node& b) {
	return a.e > b.e;
}

void process() {
	int K, N;
	double a = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &N, &a);
		if (m.find(N) != m.end()) {
			m[N] += a;
		}
		else {
			m[N] = a;
		}
	}
}

int main() {
	process();
	process();
	vector<node> ans;
	for (auto& it : m) {
		if (it.second != 0) {
			ans.push_back(node{ it.first,it.second });
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d", ans.size());
	for (auto& it : ans) {
		printf(" %d %.1f", it.e, it.c);
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int> > v;
vector<int> retailer;
int N;
double P, r, ans = 0;
void solve(int cur, int depth) {
	if (retailer[cur] != -1) {
		ans += retailer[cur] * P * pow(r + 1, depth);
		return;
	}
	for (int i = 0; i < v[cur].size(); i++) {
		solve(v[cur][i], depth + 1);
	}
}
int main() {
	cin >> N >> P >> r;
	r /= 100;
	v.resize(N);
	retailer.resize(N, -1);
	for (int i = 0; i < N; i++) {
		int K, amount;
		scanf("%d", &K);
		if (K == 0) {
			scanf("%d", &amount);
			retailer[i] = amount;
		}
		for (int j = 0; j < K; j++) {
			int temp;
			scanf("%d", &temp);
			v[i].push_back(temp);
		}
	}
	solve(0, 0);
	printf("%.1lf", ans);
	return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<int, int> fav;
vector<int> seq;
vector<int> dp;
int main() {
	int n, m, l, t, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		fav[t] = i;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> t;
		if (fav.count(t) == 1) {
			seq.push_back(fav[t]);
		}
	}
	dp.resize(seq.size());
	for (int i = 0; i < seq.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq[i] >= seq[j]) {
				dp[i] = max(dp[i], dp[j] + 1);	//等于i前面的最长的序列+1
			}
		}
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	return 0;
}
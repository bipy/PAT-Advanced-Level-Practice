#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[10010];
bool choice[10010][105];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	vector<int> seq, ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp <= m) {
			seq.push_back(temp);
		}
	}
	n = seq.size();
	sort(seq.begin(), seq.end(), cmp);
	for (int i = 0; i < n; i++) {
		for (int v = m; v >= seq[i]; v--) {
			//dp[v] = max(dp[v], dp[v - seq[i]] + seq[i]);
			if (dp[v] <= dp[v - seq[i]] + seq[i]) {
				dp[v] = dp[v - seq[i]] + seq[i];
				choice[i][v] = true;
			}
		}
	}
	if (dp[m] != m) {
		printf("No Solution");
		return 0;
	}
	int index = n - 1;
	for (int v = m; v > 0; index--) {
		if (choice[index][v] == true) {
			v -= seq[index];
			ans.push_back(seq[index]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		i == 0 ? printf("%d", ans[i]) : printf(" %d", ans[i]);
	}
	return 0;
}
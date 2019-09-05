//dfs最后一个测试点超时，应该使用dp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> coins, t, ans;
int n, m;
bool found = false;
void find(int index, int sum, vector<int> pocket) {
	if (sum == m) {
		ans = pocket;
		found = true;
		return;
	}
	for (int i = index + 1; found == false && i < coins.size() && sum + coins[i] <= m; i++) {
		vector<int> temp = pocket;
		temp.push_back(coins[i]);
		find(i, sum + coins[i], temp);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp <= m) {
			coins.push_back(temp);
		}
	}
	sort(coins.begin(), coins.end());
	find(-1, 0, t);
	if (!found) {
		printf("No Solution");
	}
	else {
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
	}
	return 0;
}
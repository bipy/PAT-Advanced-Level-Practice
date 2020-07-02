#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	//freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &ans[i]);
	}
	// 降序
	sort(ans.begin(), ans.end(), greater<int>());
	// 从大到小遍历，如果第i+1大的数(ans[i])小于等于i+1，即，此时满足以下两点：
	// 1. “第i大的数” 一定大于 i
	// 2. “第i+2大的数” 一定小于等于 i+2
	// 其中第一条满足了题意：有 i 个比 i 大的数，所以取 i 作为答案
	// 其中 i 的范围为：[0,N)
	for (int i = 0; i < N; i++) {
		if (ans[i] <= i + 1) {
			cout << i;
			return 0;
		}
	}
	// 由于上面唯独取不到 N 所以补上 N
	cout << N;
	return 0;
}
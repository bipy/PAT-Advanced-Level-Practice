#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> ans;
int main() {
	int m, n, t, max = 0, index;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			if (ans.count(t) == 0) {
				ans[t] = 1;
			}
			else {
				ans[t]++;
			}
		}
	}
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (it->second > max) {
			max = it->second;
			index = it->first;
		}
	}
	printf("%d", index);
	return 0;
}
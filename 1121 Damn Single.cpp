#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<int, int> couple;
unordered_set<int> guest;
vector<int> ans;
int main() {
	int N, M, a, b, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		guest.insert(temp);
	}
	for (auto it = guest.begin(); it != guest.end(); it++) {
		if (couple.find(*it) == couple.end() || guest.find(couple[*it]) == guest.end()) {
			ans.push_back(*it);
		}
	}
	sort(ans.begin(), ans.end(), less<int>());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf(i == 0 ? "%05d" : " %05d", ans[i]);
	}
	return 0;
}
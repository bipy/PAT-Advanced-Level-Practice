#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
	string id;
	int p = -1, m = -1, f = -1, score = -1;
	bool q = false;
};
unordered_map<string, node> a;
vector<node> ans;
bool cmp(const node& a, const node& b) {
	if (a.score == b.score) {
		return a.id < b.id;
	}
	return a.score > b.score;
}
int main() {
	int p, m, n;
	string s;
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++) {
		cin >> s;
		a[s].id = s;
		scanf("%d", &a[s].p);
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		a[s].id = s;
		scanf("%d", &a[s].m);
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[s].id = s;
		scanf("%d", &a[s].f);
	}
	for (auto it = a.begin(); it != a.end(); it++) {
		it->second.score = it->second.f > it->second.m ? it->second.f : round(it->second.f * 0.6 + it->second.m * 0.4);
		if (it->second.p >= 200 && it->second.score >= 60) {
			ans.push_back(it->second);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].id;
		printf(" %d %d %d %d\n", ans[i].p, ans[i].m, ans[i].f, ans[i].score);
	}
	return 0;
}
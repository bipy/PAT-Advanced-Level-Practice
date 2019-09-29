#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<string>
//Boy true, Girl false
using namespace std;
unordered_map<int, unordered_map<int, bool> > g;
unordered_map<int, unordered_map<int, bool> > samesex;
unordered_map<int, bool> gender;
struct node {
	int c1, c2;
};
bool cmp(const node& a, const node& b) {
	if (a.c1 == b.c1) {
		return a.c2 < b.c2;
	}
	return a.c1 < b.c1;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int p1 = stoi(s1), p2 = stoi(s2);
		gender[p1] = s1.length() == 4;//坑：测试点2："-0000" 无法判断正负，所以用string
		gender[p2] = s2.length() == 4;
		g[p1][p2] = g[p2][p1] = true;
		if (gender[p1] == gender[p2]) {
			samesex[p1][p2] = samesex[p2][p1] = true;//不先把同性找出来会超时
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int p1, p2;
		node temp;
		vector <node> ans;
		scanf("%d%d", &p1, &p2);
		for (auto it = samesex[p1].begin(); it != g[p1].end(); it++) {
			if (it->first != p2) {
				for (auto v = samesex[p2].begin(); v != g[p2].end(); v++) {
					if (g[it->first][v->first] && v->first != p1) {
						temp.c1 = fabs(it->first);
						temp.c2 = fabs(v->first);
						ans.push_back(temp);
					}
				}
			}
		}
		printf("%d\n", ans.size());
		if (!ans.empty()) {
			sort(ans.begin(), ans.end(), cmp);
			for (int i = 0; i < ans.size(); i++) {
				printf("%04d %04d\n", ans[i].c1, ans[i].c2);
			}
		}
	}
	return 0;
}
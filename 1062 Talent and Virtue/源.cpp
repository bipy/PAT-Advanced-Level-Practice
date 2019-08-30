#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int id, level, talent, virtue, total;
};
vector<node> ans;
bool cmp(node a, node b) {
	if (a.level == b.level) {
		if (a.total == b.total) {
			if (a.virtue == b.virtue) {
				return a.id < b.id;
			}
			return a.virtue > b.virtue;
		}
		return a.total > b.total;
	}
	return a.level < b.level;
}
int main() {
	int n, l, h;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		int tid, tv, tt;
		scanf("%d%d%d", &tid, &tv, &tt);
		if (tv >= l && tt >= l) {
			node temp;
			temp.id = tid;
			temp.talent = tt;
			temp.virtue = tv;
			temp.total = tt + tv;
			if (tv >= h && tt >= h) {
				temp.level = 1;
			}
			else if (tv >= h && tt < h) {
				temp.level = 2;
			}
			else if (tv < h && tt < h && tv >= tt) {
				temp.level = 3;
			}
			else {
				temp.level = 4;
			}
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%d %d %d\n", it->id, it->virtue, it->talent);
	}
	return 0;
}
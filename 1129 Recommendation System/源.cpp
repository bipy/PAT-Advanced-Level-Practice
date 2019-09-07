#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
struct node {
	int id, count = 0;
	bool operator < (const node& b) const {
		if (this->count == b.count) {
			return this->id < b.id;
		}
		return this->count > b.count;
	}
};
set<node> ans;
unordered_map<int, int> cnt;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		node temp;
		scanf("%d", &temp.id);
		if (i != 0) {
			printf("%d:", temp.id);
			int index = 0;
			for (auto it = ans.begin(); index++ < k && it != ans.end(); it++) {
				printf(" %d", it->id);
			}
			printf("\n");
		}
		auto it = ans.find(node{ temp.id,cnt[temp.id] });
		if (it != ans.end()) {
			ans.erase(it);
		}
		temp.count = ++cnt[temp.id];
		ans.insert(temp);
	}
	return 0;
}
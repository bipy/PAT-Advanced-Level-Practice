#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct node {
	int address, key, next;
};
vector<node> v;
unordered_map<int, node> m;
bool cmp(node a, node b) {
	return a.key < b.key;
}
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.address >> temp.key >> temp.next;
		m[temp.address] = temp;
	}
	while (s != -1) {
		v.push_back(m[s]);
		s = m[s].next;
	}
	sort(v.begin(), v.end(), cmp);

	if (v.size() == 0) {
		printf("%d -1\n", v.size());
	}
	else {
		printf("%d %05d\n", v.size(), v[0].address);
		for (auto it = v.begin(); it != v.end(); it++) {
			if (it + 1 == v.end()) {
				printf("%05d %d -1\n", it->address, it->key);
			}
			else {
				printf("%05d %d %05d\n", it->address, it->key, (it + 1)->address);
			}
		}
	}
	return 0;
}
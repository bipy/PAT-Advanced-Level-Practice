#include<iostream>
#include<unordered_map>
#include<cmath>
#include<vector>
using namespace std;
struct node {
	int address, val, next;
};
unordered_map<int, node> m;
unordered_map<int, bool> visited;
vector<node> removed;
int main() {
	int first, n;
	cin >> first >> n;
	for (int i = 0; i < n; i++) {
		int a, v, n;
		cin >> a >> v >> n;
		m[a] = node{ a,v,n };
	}
	int p = first;
	int pre = -1;
	while (p != -1) {
		if (visited.count(abs(m[p].val)) == 0) {
			visited[abs(m[p].val)] = true;
			pre = p;
		}
		else {
			removed.push_back(m[p]);
			m[pre].next = m[p].next;
		}
		p = m[p].next;
	}
	p = first;
	while (m[p].next != -1) {
		printf("%05d %d %05d\n", m[p].address, m[p].val, m[p].next);
		p = m[p].next;
	}
	printf("%05d %d -1\n", m[p].address, m[p].val);
	for (auto it = removed.begin(); it != removed.end() ; it++) {
		if (it == removed.end() - 1) {
			break;
		}
		printf("%05d %d %05d\n", it->address, it->val, (it + 1)->address);
	}
	if (!removed.empty()) {
		printf("%05d %d -1\n", removed.back().address, removed.back().val);
	}
	return 0;
}
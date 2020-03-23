#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
struct node {
	int address, data, next;
};
unordered_map<int, node> m;
vector<node> v, s;
int main() {
	int start, N, K;
	cin >> start >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, d, n;
		scanf("%d %d %d", &a, &d, &n);
		m[a] = node{ a,d,n };
	}
	int p = start;
	s.push_back(m[p]);
	while (m[p].next != -1) {
		s.push_back(m[m[p].next]);
		if (s.size() == K) {
			while (!s.empty()) {
				v.push_back(s.back());
				s.pop_back();
			}
		}
		p = m[p].next;
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}
	for (auto it = v.begin(); it != v.end() - 1; it++) {
		printf("%05d %d %05d\n", it->address, it->data, (it + 1)->address);
	}
	printf("%05d %d -1\n", v.back().address, v.back().data);
	return 0;
}
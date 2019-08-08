#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, bool> m;
vector<int> stream;
int main() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		stream.push_back(t);
		if (m.count(t) == 0) {
			m[t] = true;
		}
		else {
			m[t] = false;
		}
	}
	for (auto it = stream.begin(); it != stream.end(); it++) {
		if (m[*it]) {
			printf("%d", *it);
			return 0;
		}
	}
	printf("None");
	return 0;
}
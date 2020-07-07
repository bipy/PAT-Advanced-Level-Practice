#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main() {
	int N, M, S;
	cin >> N >> M >> S;
	vector<string> seq, ans;
	unordered_map<string, bool> m;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		seq.emplace_back(s);
		m[s] = false;
	}
	for (int i = S - 1; i < N;) {
		if (m[seq[i]]) {
			i++;
			continue;
		}
		m[seq[i]] = true;
		ans.emplace_back(seq[i]);
		i += M;
	}
	if (ans.empty()) {
		printf("Keep going...");
		return 0;
	}
	for (auto& it : ans) {
		cout << it << endl;
	}
	return 0;
}
#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
/*
题干说两个数的sum一样才叫 Friend Numbers
不明白为什么只有一个也算，比如样例中的 (12 -> 3)
*/
unordered_set<int> m;
vector<int> ans;
int main() {
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		int sum = 0;
		while (true) {
			char c;
			scanf("%c", &c);
			if (c == ' ' || c == '\n') {
				m.insert(sum);
				break;
			}
			sum += c - '0';
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		ans.push_back(*it);
	}
	sort(ans.begin(), ans.end(), less<int>());
	printf("%d\n%d", ans.size(), ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	return 0;
}
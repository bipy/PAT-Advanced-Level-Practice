#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
vector<unordered_set<int> > seq;
int main() {
	int n, k, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		unordered_set<int> temp;
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			int v;
			scanf("%d", &v);
			temp.insert(v);
		}
		seq.push_back(temp);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int q1, q2, same = 0;
		scanf("%d%d", &q1, &q2);
		q1--; q2--;
		unordered_map<int, bool> check;
		for (auto it = seq[q1].begin(); it != seq[q1].end(); it++) {
			check[*it] = true;
		}
		for (auto it = seq[q2].begin(); it != seq[q2].end(); it++) {
			if (check[*it] == true) {
				same++;
			}
		}
		printf("%.1f%%\n", 100.0 * same / (seq[q1].size() + seq[q2].size() - same));
	}
	return 0;
}
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, vector<int> > a;
int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, temp, sum = 0, minus = 0;
		scanf("%d", &num);
		vector<bool> v(n, false);
		vector<int> seq(num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &seq[j]);
			v[seq[j]] = true;
			sum += a[seq[j]].size();
		}
		for (int j = 0; j < num; j++) {
			for (auto it = a[seq[j]].begin(); it != a[seq[j]].end(); it++) {
				if (v[*it]) {
					minus++;
				}
			}
		}
		sum - minus / 2 == m ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
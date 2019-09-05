#include<iostream>
#include<vector>
using namespace std;
struct node {
	int value, count = 1;
};
vector<vector<int> > ans;
int main() {
	int d, n;
	cin >> d >> n;
	ans.resize(1);
	ans[0].push_back(d);
	for (int i = 0; i < n - 1; i++) {
		vector<node> temp;
		for (int j = 0; j < ans[i].size(); j++) {
			if (j == 0 || ans[i][j] != ans[i][j - 1]) {
				node t;
				t.value = ans[i][j];
				temp.push_back(t);
			}
			else {
				temp[temp.size() - 1].count++;
			}
		}
		vector<int> seq;
		for (int j = 0; j < temp.size(); j++) {
			seq.push_back(temp[j].value);
			seq.push_back(temp[j].count);
		}
		ans.push_back(seq);
	}
	for (int i = 0; i < ans[n - 1].size(); i++) {
		printf("%d", ans[n - 1][i]);
	}
	return 0;
}
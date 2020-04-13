#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
vector<vector<int> > ans;
bool cmp(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}
void dfs(int cur, int i, vector<int>& v) {
	if (cur % (i + 1) == 0 && i <= sqrt(N)) {
		v.push_back(i + 1);
		dfs(cur / (i + 1), i + 1, v);
	}
	else {
		ans.push_back(v);
	}
}
int main() {
	cin >> N;
	for (int i = 2; i < sqrt(N); i++) {
		if (N % i == 0) {
			vector<int> temp;
			temp.push_back(i);
			dfs(N / i, i, temp);
		}
	}
	ans.push_back(vector<int>(1, N));
	sort(ans.begin(), ans.end(), cmp);
	int maxSize = 1;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (maxSize < it->size()) {
			maxSize = it->size();
		}
	}
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (maxSize == it->size()) {
			cout << maxSize << endl;
			printf("%d", it->at(0));
			for (int i = 1; i < maxSize; i++) {
				printf("*%d", it->at(i));
			}
			break;
		}
	}
	return 0;
}
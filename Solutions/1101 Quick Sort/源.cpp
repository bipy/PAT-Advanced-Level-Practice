#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int index, val;
	bool flag;
};
bool cmp(const node& a, const node& b) {
	return a.val < b.val;
}
vector<int> ans;
int main() {
	int n, max = -1;
	cin >> n;
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		// 保证当前数大于前面所有数
		v[i] = node{ i,temp,max < temp };
		if (max < temp) {
			max = temp;
		}
	}
	sort(v.begin(), v.end(), cmp);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].flag && v[i].index == i) {
			count++;
			ans.push_back(v[i].val);
		}
	}
	cout << count << endl;
	for (int i = 0; i < ans.size(); i++) {
		i == 0 ? printf("%d", ans[i]) : printf(" %d", ans[i]);
	}
	cout << endl;
	return 0;
}
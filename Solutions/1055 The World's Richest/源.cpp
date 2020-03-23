#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	string name;
	int age, worth;
};
vector<node> ans;
bool cmp(node a, node b) {
	if (a.worth == b.worth) {
		if (a.age == b.age) {
			return a.name < b.name;
		}
		return a.age < b.age;
	}
	return a.worth > b.worth;
}
int main() {
	int n, k;
	cin >> n >> k;
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ans[i].name;
		scanf("%d %d", &ans[i].age, &ans[i].worth);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 1; i <= k; i++) {
		printf("Case #%d:\n", i);
		int num, amin, amax;
		scanf("%d %d %d", &num, &amin, &amax);
		vector<node> temp;
		for (int j = 0; j < n; j++) {
			if (ans[j].age >= amin && ans[j].age <= amax) {
				temp.push_back(ans[j]);
			}
			if (temp.size() >= num) {
				break;
			}
		}
		if (temp.empty()) {
			printf("None\n");
		}
		else {
			for (int j = 0; j < temp.size(); j++) {
				cout << temp[j].name;
				printf(" %d %d\n", temp[j].age, temp[j].worth);
			}
		}
	}
	return 0;
}
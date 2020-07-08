#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	string name;
	double TWS = 0, num = 0;
};
vector<node> ans;
unordered_map<string, node> school;
unordered_map<char, double> c = { {'T',1.5},{'A',1},{'B',1 / 1.5} };
bool cmp(const node& a, const node& b) {
	if (a.TWS == b.TWS) {
		if (a.num == b.num) {
			return a.name < b.name;
		}
		return a.num < b.num;
	}
	return a.TWS > b.TWS;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string id, sname;
		double score;
		cin >> id >> score >> sname;
		//tolower前不加::报错，全局作用域
		transform(sname.begin(), sname.end(), sname.begin(), ::tolower);
		school[sname].name = sname;
		school[sname].num++;
		school[sname].TWS += score * c[id[0]];
	}
	for (auto it = school.begin(); it != school.end(); it++) {
		it->second.TWS = (int)it->second.TWS;
		ans.push_back(it->second);
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	int rank = 1;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0 || ans[i].TWS == ans[i - 1].TWS) {
			printf("%d ", rank);
		}
		else {
			rank = i + 1;
			printf("%d ", rank);
		}
		cout << ans[i].name;
		printf(" %d %d\n", (int)ans[i].TWS, (int)ans[i].num);
	}
	return 0;
}
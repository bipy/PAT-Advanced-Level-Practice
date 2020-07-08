#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct user {
	vector<string> record;
	double total = 0;
};
map<string, user> bill;
int price[24];
int daycost = 0;
int calctime(string s) {
	int t1, t2;
	t1 = stoi(s.substr(0, 2)) * 24 * 60 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
	t2 = stoi(s.substr(9, 2)) * 24 * 60 + stoi(s.substr(12, 2)) * 60 + stoi(s.substr(15, 2));
	return t2 - t1;
}
int calccost(string s) {
	int cost = 0;
	if (s.substr(0, 2) != s.substr(9, 2)) {
		cost += (stoi(s.substr(9, 2)) - stoi(s.substr(0, 2))) * daycost;
	}
	cost += stoi(s.substr(15, 2)) * price[stoi(s.substr(12, 2))];
	cost -= stoi(s.substr(6, 2)) * price[stoi(s.substr(3, 2))];
	for (int i = 0; i < stoi(s.substr(12, 2)); i++) {
		cost += price[i] * 60;
	}
	for (int i = 0; i < stoi(s.substr(3, 2)); i++) {
		cost -= price[i] * 60;
	}
	return cost;
}
bool cmp(string a, string b) {
	return a.substr(3, 8) < b.substr(3, 8);
}
int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	string month;
	for (int i = 0; i < 24; i++) {
		cin >> price[i];
		daycost += price[i] * 60;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		string id, record;
		cin >> id;
		getchar();
		getline(cin, record);
		if (bill.find(id) == bill.end()) {
			user newuser;
			bill[id] = newuser;
		}
		bill[id].record.push_back(record);
	}
	for (auto it = bill.begin(); it != bill.end(); it++) {
		sort(it->second.record.begin(), it->second.record.end(), cmp);
		int flag = 0;	//判断此人是否消费过，不消费的不输出
		for (int i = 1; i < it->second.record.size(); i++) {
			string formed;
			if (it->second.record[i].substr(12) == "off-line" && it->second.record[i - 1].substr(12) == "on-line") {
				if (flag == 0) {
					cout << it->first << " " << it->second.record[0].substr(0, 2) << endl;
					flag = 1;
				}
				formed = it->second.record[i - 1].substr(3, 8) + " " + it->second.record[i].substr(3, 8);
				int time = calctime(formed);
				double cost = calccost(formed) / 100.0;
				cout << formed;
				printf(" %d $%.2f\n", time, cost);
				it->second.total += cost;
			}
		}
		if (flag == 1) {
			printf("Total amount: $%.2f\n", it->second.total);
		}
	}
	return 0;
}
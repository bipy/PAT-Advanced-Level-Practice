#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
struct user {
	vector<string> record;
	stack<string> list_status;
	stack<string> list_record;
	string username;
	double total;
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
int calccost(int time, string s) {
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
	/*
	if (s.substr(3, 2) + s.substr(6, 2) > s.substr(12, 2) + s.substr(15, 2)) {
		cost += (60 - stoi(s.substr(6, 2))) * price[stoi(s.substr(3, 2))];
		for (int i = stoi(s.substr(3, 2))+1; i < 24; i++) {
			cost += price[i] * 60;
		}
		for (int i = 0; i < stoi(s.substr(12, 2)); i++) {
			cost += price[i] * 60;
		}
		cost += stoi(s.substr(15, 2)) * price[stoi(s.substr(12, 2))];
		cost -= daycost;
	}
	else if (s.substr(3, 2) + s.substr(6, 2) < s.substr(12, 2) + s.substr(15, 2)) {
		cost += (60 - stoi(s.substr(6, 2))) * price[stoi(s.substr(3, 2))];
		for (int i = 0; i < stoi(s.substr(12, 2)); i++) {
			cost += price[i] * 60;
		}
		cost += (60 - stoi(s.substr(6, 2))) * price[stoi(s.substr(3, 2))];
	}*/
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
		string id, time, status;
		cin >> id >> time >> status;
		month = time.substr(0, 2);
		time = time.substr(3);
		if (bill.find(id) == bill.end()) {
			user newuser;
			newuser.total = 0;
			newuser.username = id;
			bill[id] = newuser;
		}
		if (bill[id].list_status.empty() || bill[id].list_status.top() == status) {
			bill[id].list_status.push(status);
			bill[id].list_record.push(time);
		}
		else if (bill[id].list_status.top() != status) {
			if (bill[id].list_record.top() > time) {
				bill[id].record.push_back(time + " " + bill[id].list_record.top());
			}
			else {
				bill[id].record.push_back(bill[id].list_record.top() + " " + time);
			}
			bill[id].list_status.pop();
			bill[id].list_status.pop();
		}
	}
	for (auto it = bill.begin(); it != bill.end(); it++) {
		cout << it->first << " " << month << endl;
		sort(it->second.record.begin(), it->second.record.end());
		for (string s : it->second.record) {
			int time = calctime(s);
			int cost = calccost(time, s);
			printf("%s %d $%.2f\n", s, time, cost / 100.0);
			it->second.total += cost;
		}
		printf("Total amount: $%.2f\n", it->second.total / 100.0);
	}
	return 0;
}
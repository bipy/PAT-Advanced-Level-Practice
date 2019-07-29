#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	int arr;
	int cost;
	int wait;
	int vip;
};
struct table {
	int curtime = 8 * 3600;
	int id;
	int vip = 0;
	int served = 0;
};
vector<node> users;
vector<table> tables;
vector<node> waitinline;
bool cmp(node a, node b) {
	return a.arr < b.arr;
}
bool tablecmp(table a, table b) {
	if (a.curtime != b.curtime) {
		return a.curtime < b.curtime;
	}
	return a.id < b.id;
}
int findvip(int x) {
	for (int i = x + 1; i < users.size(); i++) {
		if (users[i].vip == 1) {
			return i;
		}
	}
	return -1;
}
void serve(int tableindex, int userindex) {
	tables[tableindex].served++;
	if (tables[tableindex].curtime < users[userindex].arr) {
		tables[tableindex].curtime == users[userindex].arr;
	}
	tables[tableindex].curtime += users[userindex].cost;
}
int main() {
	int n, k, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node temp;
		int hour, minute, second;
		scanf("%02d:%02d:%02d %d %d", &hour, &minute, &second, &temp.cost, &temp.vip);
		temp.arr = hour * 3600 + minute * 60 + second;
		users.push_back(temp);
	}
	cin >> k >> m;
	tables.resize(k);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		tables[t - 1].vip = 1;
	}
	for (int i = 0; i < k; i++) {
		tables[i].id = i;
	}
	sort(users.begin(), users.end(), cmp);
	for (int i = 0; i < users.size(); i++) {
		int j = i;
		sort(tables.begin(), tables.end(), tablecmp);
		while(users[j].arr<tables[0].curtime) {
			waitinline.push_back(users[j++]);
		}
		if (i <= k) {
			if (tables[i].vip == 1) {
				if (users[i].vip == 1) {
					serve(i, i);
				}
				else {
					int nextvip = findvip(i);
					if (nextvip != -1) {
						if (users[i].arr < users[nextvip].arr) {
							serve(i, i);
						}
						else {
							serve(i, nextvip);
						}
					}
				}

			}
			else {

			}
		}
		return 0;
	}
}
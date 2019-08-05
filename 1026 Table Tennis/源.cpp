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
void serve(int tableindex, int arr, int cost) {
	tables[tableindex].served++;
	if (tables[tableindex].curtime < arr) {
		tables[tableindex].curtime == arr;
	}
	tables[tableindex].curtime += cost;
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
	for (auto it = users.begin(); it != users.end(); it++) {
		if (it->vip == 1) {
			sort(tables.begin(), tables.end(), tablecmp);
			serve(0, it->arr, it->cost);
			it->wait = tables[0].curtime - it->cost - it->arr;
		}
		else {
			bool flag = false;
			while (!flag) {
				sort(tables.begin(), tables.end(), tablecmp);
				if (tables[0].vip == 1) {
					for (auto k = it; k != users.end(); k++) {
						if (k->vip == 1) {
							if (k->arr < tables[0].curtime) {
								serve(0, k->arr, k->cost);
								users.erase(k);

								continue;
							}
							break;
						}
					}
				}
				serve(0, it->arr, it->cost);
				it->wait = tables[0].curtime - it->cost - it->arr;
				flag = true;
			}
		}
	}
	return 0;

}
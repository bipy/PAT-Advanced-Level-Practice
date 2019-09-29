#include<iostream>
#include<algorithm>
#include<vector>
#define maxN 101
using namespace std;
struct node {
	string id;
	int score;
	int location;
	int lrank;
};
vector<node> list;
bool cmp(node a, node b) {
	if(a.score!=b.score) {
		return a.score > b.score;
	}
	return a.id < b.id;
}
int main() {
	int n, k, rank = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<node> local;
		cin >> k;
		for (int j = 0; j < k; j++) {
			node temp;
			cin >> temp.id >> temp.score;
			temp.location = i;
			local.push_back(temp);
		}
		sort(local.begin(), local.end(), cmp);
		for (int j = 0; j < k; j++) {
			if (j > 0 && local[j].score == local[j - 1].score) {
				local[j].lrank = local[j - 1].lrank;
			}
			else {
				local[j].lrank = j + 1;
			}
			list.push_back(local[j]);
		}
	}
	sort(list.begin(), list.end(), cmp);
	cout << list.size() << endl;
	for (int i = 0; i < list.size(); i++) {
		if (i > 0 && list[i].score < list[i - 1].score) {
			rank = i + 1;
		}
		cout << list[i].id;
		printf(" %d %d %d\n", rank, list[i].location, list[i].lrank);
	}
	return 0;
}
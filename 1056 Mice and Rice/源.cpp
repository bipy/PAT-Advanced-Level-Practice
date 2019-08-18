#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int weight, rank, id, order;
};
vector<node> mice;
vector<int> victor, temp;
bool cmp(node a, node b) {
	return a.order < b.order;
}
bool cmp2(node a, node b) {
	return a.id < b.id;
}
int main() {
	int np, ng;
	cin >> np >> ng;
	mice.resize(np);
	victor.resize(np);
	for (int i = 0; i < np; i++) {
		cin >> mice[i].weight;
		mice[i].id = i;
		victor[i] = i;
	}
	for (int i = 0; i < np; i++) {
		int t;
		cin >> t;
		mice[t].order = i;
	}
	sort(mice.begin(), mice.end(), cmp);
	while (victor.size() > 1) {
		int group = victor.size() % ng > 0 ? victor.size() / ng + 1 : victor.size() / ng;
		int currank = group + 1;
		temp = victor;
		victor.clear();
		for (int i = 0; i < temp.size(); i += ng) {
			int max = i;
			for (int j = i; j < temp.size() && j < i + ng; j++) {
				if (mice[temp[j]].weight > mice[temp[max]].weight) {
					max = j;
				}
			}
			for (int j = i; j < temp.size() && j < i + ng; j++) {
				if (mice[temp[j]].weight == mice[temp[max]].weight) {
					victor.push_back(temp[j]);
				}
				else {
					mice[temp[j]].rank = currank;
				}
			}
		}
		temp.clear();
	}
	mice[victor[0]].rank = 1;
	sort(mice.begin(), mice.end(), cmp2);
	printf("%d", mice[0].rank);
	for (int i = 1; i < np; i++) {
		printf(" %d", mice[i].rank);
	}
	return 0;
}
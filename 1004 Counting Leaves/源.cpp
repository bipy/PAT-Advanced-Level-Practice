#include<iostream>
#include<vector>
#include<map>
#include<string>
#define root "01"
using namespace std;
int N, M;
map<string, vector<string> > Tree;
void count(vector<string> v) {
	int cnt = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		if (Tree.count(*it) == 0) {
			cnt++;
		}
	}
	cout << " " << cnt;
}
void init(vector<string> v) {
	count(v);
	vector<string> next;
	for (auto it = v.begin(); it != v.end(); it++) {
		if (Tree.count(*it) != 0) {
			for (auto t = Tree[*it].begin(); t != Tree[*it].end(); t++) {
				next.push_back(*t);
			}
		}
	}
	if (!next.empty()) {
		init(next);
	}
}
void process() {
	for (int i = 0; i < M; i++) {
		string s;
		int num;
		cin >> s >> num;
		vector<string> child;
		for (int j = 0; j < num; j++) {
			string t;
			cin >> t;
			child.push_back(t);
		}
		Tree[s] = child;
	}
	cout << 0;
	init(Tree[root]);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	cin >> N >> M;
	if (N == 0);
	else if (N == 1) {
		cout << 1 << endl;
	}
	else if (N == 2) {
		cout << 0 << " " << 1 << endl;
	}
	else {
		process();
	}
	return 0;
}
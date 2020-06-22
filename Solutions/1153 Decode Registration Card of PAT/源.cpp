#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
//一开始date使用了int型，没考虑到00年这种情况，导致答案错误
struct node {
	string id,date;
	int score, site;
	char level;
};
struct site {
	int num, count = 0;
};
unordered_map<char, vector<node> > levelmap;
unordered_map<string, vector<node> > datemap;
unordered_map<int, vector<node> > sitemap;
bool levelcmp(const node& a, const node& b) {
	if (a.score == b.score) {
		return a.id < b.id;
	}
	return a.score > b.score;
}
bool datecmp(const site& a, const site& b) {
	if (a.count == b.count) {
		return a.num < b.num;
	}
	return a.count > b.count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.id >> temp.score;
		temp.level = temp.id[0];
		temp.site = stoi(temp.id.substr(1, 3));
		temp.date = temp.id.substr(4, 6);
		levelmap[temp.level].push_back(temp);
		datemap[temp.date].push_back(temp);
		sitemap[temp.site].push_back(temp);
	}
	for (auto it = levelmap.begin(); it != levelmap.end(); it++) {
		sort(it->second.begin(), it->second.end(), levelcmp);
	}
	for (int i = 1; i <= m; i++) {
		int model;
		scanf("%d", &model);
		if (model == 1) {
			char l;
			scanf(" %c", &l);
			printf("Case %d: %d %c\n", i, model, l);
			if (levelmap[l].empty()) {
				printf("NA\n");
				continue;
			}
			for (int i = 0; i < levelmap[l].size(); i++) {
				cout << levelmap[l][i].id;
				printf(" %d\n", levelmap[l][i].score);
			}
		}
		else if (model == 2) {
			int s, sum = 0;
			scanf("%d", &s);
			printf("Case %d: %d %d\n", i, model, s);
			if (sitemap[s].empty()) {
				printf("NA\n");
				continue;
			}
			for (auto it = sitemap[s].begin(); it != sitemap[s].end(); it++) {
				sum += it->score;
			}
			printf("%d %d\n", sitemap[s].size(), sum);
		}
		else if (model == 3) {
			string d;
			cin >> d;
			printf("Case %d: %d %s\n", i, model, d.c_str());
			if (datemap[d].empty()) {
				printf("NA\n");
				continue;
			}
			unordered_map<int, int> m;
			for (auto it = datemap[d].begin(); it != datemap[d].end(); it++) {
				m[it->site]++;
			}
			vector<site> v;
			for (auto it = m.begin(); it != m.end(); it++) {
				site temp;
				temp.num = it->first;
				temp.count = it->second;
				v.push_back(temp);
			}
			sort(v.begin(), v.end(), datecmp);
			for (auto it = v.begin(); it != v.end(); it++) {
				printf("%d %d\n", it->num, it->count);
			}
		}
	}
	return 0;
}
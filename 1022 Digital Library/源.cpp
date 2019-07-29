#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
unordered_map<string, vector<string> > index;
void insert(string s, string id) {
	if (index.count(s) == 0) {
		vector<string> temp;
		temp.push_back(id);
		index[s] = temp;
	}
	else {
		index[s].push_back(id);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	int n, m;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string id, title, author, keyword, publisher, published_year;
		vector<string> keywords;
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		while (cin >> keyword) {
			keywords.push_back(keyword);
			if (getchar() == '\n') {
				break;
			}
		}
		getline(cin, publisher);
		getline(cin, published_year);
		insert(title, id);
		insert(author, id);
		insert(publisher, id);
		insert(published_year, id);
		for (string s : keywords) {
			insert(s, id);
		}
	}
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++) {
		string query;
		int label;
		scanf("%d: ", &label);
		getline(cin, query);
		cout << label << ": " << query << endl;
		if (index.count(query) == 0) {
			printf("Not Found\n");
		}
		else {
			sort(index[query].begin(), index[query].end());
			for (auto it = index[query].begin(); it != index[query].end(); it++) {
				cout << *it << endl;
			}
		}
	}
	return 0;
}
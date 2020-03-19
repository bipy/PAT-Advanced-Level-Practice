#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
void toUpperClass(string &s) {
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it >= 'a' && *it <= 'z') {
			*it = *it - 'a' + 'A';
		}
	}
}
int main() {
	string ori, loss;
	vector<char> ans;
	unordered_map<char, bool> check;
	cin >> ori >> loss;
	toUpperClass(ori);
	toUpperClass(loss);
	int i = 0, j = 0;
	for (; i < ori.length() && j < loss.length();i++, j++) {
		while (ori[i] != loss[j]) {
			if (check.count(ori[i]) == 0) {
				ans.push_back(ori[i]);
				check[ori[i]] = true;
			}
			i++;
		}
	}
	while (i < ori.length()) {
		if (check.count(ori[i]) == 0) {
			ans.push_back(ori[i]);
			check[ori[i]] = true;
		}
		i++;
	}
	for (auto it = ans.begin(); it != ans.end();it++) {
		cout << *it;
	}
	return 0;
}
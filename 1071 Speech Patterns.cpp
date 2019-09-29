#include<iostream>
#include<cctype>
#include<string>
#include<unordered_map>
using namespace std;
string s, ans;
unordered_map<string, int> m;
int main() {
	int pre = 0;
	getline(cin, s);
	s.append("$");
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			s[i] = tolower(s[i]);
		}
		else if (!isalnum(s[i])) {
			if (i > pre) {
				m[s.substr(pre, i - pre)]++;
			}
			pre = i + 1;
		}
	}
	int max = -1;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			ans = it->first;
			max = it->second;
		}
	}
	cout << ans << " " << max;
	return 0;
}
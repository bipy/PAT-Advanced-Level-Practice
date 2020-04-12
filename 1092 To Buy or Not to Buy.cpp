#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<char, int> m;
int main() {
	int less = 0, more = 0;
	string s1, s2;
	cin >> s1 >> s2;
	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (m.count(*it) == 0) {
			m[*it] = 1;
		}
		else {
			m[*it]++;
		}
	}
	for (auto it = s2.begin(); it != s2.end(); it++) {
		if (m.count(*it) == 0|| m[*it] == 0) {
			less++;
		}
		else if (m[*it] > 0) {
			m[*it]--;
		}
	}
	if (less == 0) {
		cout << "Yes " << s1.length() - s2.length();
	}
	else {
		cout << "No " << less;
	}


	return 0;
}
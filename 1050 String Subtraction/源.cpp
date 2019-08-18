#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<char, bool> m;
string s, d;
int main() {
	getline(cin, s);
	getline(cin, d);
	for (auto it = s.begin(); it != s.end(); it++) {
		m[*it] = true;
	}
	for (auto it = d.begin(); it != d.end(); it++) {
		m[*it] = false;
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		if (m[*it]) {
			printf("%c", *it);
		}
	}
	return 0;
}
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<char, string> english;
	english['0'] = "zero";
	english['1'] = "one";
	english['2'] = "two";
	english['3'] = "three";
	english['4'] = "four";
	english['5'] = "five";
	english['6'] = "six";
	english['7'] = "seven";
	english['8'] = "eight";
	english['9'] = "nine";
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += n[i]-'0';
	}
	string s = to_string(sum);
	cout << english[s[0]];
	for (int i = 1; i < s.length(); i++) {
		cout << " " << english[s[i]];
	}
	return 0;
}
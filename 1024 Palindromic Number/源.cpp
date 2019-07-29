#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindromic(string s) {
	int size = s.length() - 1;
	bool flag = true;
	for (int i = 0; i <= size / 2; i++) {
		if (s[i] != s[size - i]) {
			flag = false;
		}
	}
	return flag;
}
int main() {
	int k;
	string s, rs;
	cin >> s >> k;
	for (int i = 0; i < k; i++) {
		if (isPalindromic(s)) {
			k = i;
			break;
		}
		int w = 0;
		rs = s;
		reverse(rs.begin(), rs.end());
		for (int i = s.length() - 1; i >= 0; i--) {
			int sum = (s[i] - '0') + (rs[i] - '0');
			s[i] = to_string((sum % 10 + w) % 10)[0];
			if (sum % 10 + w >= 10 || sum >= 10) {
				w = 1;
			}
			else {
				w = 0;
			}
		}
		if(w==1) {
			s = '1' + s;
		}
	}
	cout << s << endl << k;
	return 0;
}
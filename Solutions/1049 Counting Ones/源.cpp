#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int p1(string s) {
	int count = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		int left = i == 0 ? 0 : stod(s.substr(0, i)), right = i == s.length() - 1 ? 0 : stod(s.substr(i + 1));
		if (s[i] == '0') {
			count += left * pow(10, s.length() - 1 - i);
		}
		else if (s[i] - '0' == 1) {
			count += left * pow(10, s.length() - 1 - i) + right + 1;
		}
		else {
			count += (left + 1) * pow(10, s.length() - 1 - i);
		}
	}
	return count;
}
int p2(int n) {
	int left = 0, right = 0, a = 1, now = 1, ans = 0;
	while (n / a) {
		left = n / (a * 10), now = n / a % 10, right = n % a;
		if (now == 0) {
			ans += left * a;
		}
		else if (now == 1) {
			ans += left * a + right + 1;
		}
		else {
			ans += (left + 1) * a;
		}
		a *= 10;
	}
	return ans;
}
int main() {
	string s;
	cin >> s;
	cout << p1(s);
	//cout << p2(stod(s));
	return 0;
}
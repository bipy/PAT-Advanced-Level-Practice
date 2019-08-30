#include<iostream>
#include<string>
using namespace std;
int process(string& s, int n) {
	int b, dot;
	for (b = 0; s[b] == '0'; b++);
	s = s.substr(b);
	for (dot = 0; dot < s.length() && s[dot] != '.'; dot++);
	s.erase(dot, 1);
	if (dot == 0) {
		for (b = 0; s[b] == '0'; b++);
		s = s.substr(b);
		if (!s.empty()) {
			dot -= b;
		}
	}
	while (s.length() < n) {
		s.append("0");
	}
	s = s.substr(0, n);
	return dot;
}
int main() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	int dot1 = process(s1, n), dot2 = process(s2, n);
	if (dot1 == dot2 && s1 == s2) {
		printf("YES");
		cout << " 0." << s1 << "*10^" << dot1;
		return 0;
	}
	printf("NO");
	cout << " 0." << s1 << "*10^" << dot1;
	cout << " 0." << s2 << "*10^" << dot2;
	return 0;
}
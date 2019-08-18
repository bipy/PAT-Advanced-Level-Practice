#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2;
	int n, dot, b1, b2;
	bool eq = true;
	cin >> n >> s1 >> s2;
	for (b1 = 0; s1[b1] == '0'; b1++);
	s1 = s1.substr(b1);
	for (b2 = 0; s1[b2] == '0'; b2++);
	s2 = s2.substr(b2);
	for (dot = 0; dot < s1.length() && s1[dot] != '.'; dot++);
	if (dot == s2.length() || (dot < s2.length() && s2[dot] == '.')) {
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			printf("YES");
			cout << " 0." << s1.substr(0, n) << "*10^" << dot;
			return 0;
		}
	}
	printf("NO");
	cout << " 0." << s1.substr(0, n) << "*10^" << dot;
	for (dot = 0; dot < s2.length() && s2[dot] != '.'; dot++);
	cout << " 0." << s2.substr(0, n) << "*10^" << dot;
	return 0;
}
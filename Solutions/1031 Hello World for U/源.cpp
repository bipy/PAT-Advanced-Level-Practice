#include<iostream>
#include<string>
using namespace std;
int main() {
	int n1, n2, n3, N;
	string s;
	cin >> s;
	N = s.length();
	n1 = n3 = (N + 2) / 3;
	n2 = N + 2 - n1 - n3;
	for (int i = 0; i < n1 - 1; i++) {
		printf("%c", s[i]);
		for (int j = 0; j < n2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", s[N - i - 1]);
	}
	cout << s.substr(n1 - 1, n2);
	return 0;
}
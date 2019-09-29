#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int max = 1, slength = s.length();
	for (int i = 0; i < slength - 2; i++) {
		if (s[i] == s[i + 1]) {
			int j = i, k = i + 1, length = 0;
			while (j >= 0 && k < slength && s[j--] == s[k++]) {
				length += 2;
			}
			if (length > max) {
				max = length;
			}
		}
		if (s[i] == s[i + 2]) {
			int j = i, k = i + 2, length = 1;
			while (j >= 0 && k < slength && s[j--] == s[k++]) {
				length += 2;
			}
			if (length > max) {
				max = length;
			}
		}
	}
	printf("%d", max);
	return 0;
}
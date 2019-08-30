#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string date[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int main() {
	bool first = true;
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	for (int i = 0; i < s1.length() && i < s2.length(); i++) {
		if (s1[i] == s2[i]) {
			if (first && isupper(s1[i]) && s1[i] <= 'G') {
				cout << date[s1[i] - 'A'];
				first = false;
			}
			else if (!first && isupper(s1[i]) && s1[i] <= 'N') {
				printf(" %02d:", s1[i] - 'A' + 10);
				break;
			}
			else if (!first && isdigit(s1[i])) {
				printf(" %02d:", s1[i] - '0');
				break;
			}
		}
	}
	for (int i = 0; i < s3.length() && i < s4.length(); i++) {
		if (s3[i] == s4[i] && isalpha(s3[i])) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}
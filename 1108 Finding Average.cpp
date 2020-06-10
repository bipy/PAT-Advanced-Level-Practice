#include<iostream>
#include<string>
#include<cctype>
#define ACCURATE_DECIMAL 2 
using namespace std;
int main() {
	int N;
	cin >> N;
	double sum = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		string s, abs;
		cin >> s;
		int cnt = 0;
		bool flag = true;
		abs = s.substr(s[0] == '-' ? 1 : 0);
		for (auto it = abs.begin(); it != abs.end(); it++) {
			if (!isdigit(*it) && *it != '.') {
				flag = false;
				break;
			}
			if (*it == '.') {
				while (++it != abs.end()) {
					cnt++;
					if (!isdigit(*it) || cnt > ACCURATE_DECIMAL) {
						flag = false;
						break;
					}
				}
				break;
			}
		}
		if (flag) {
			double cur = stod(s);
			if (cur > 1000 || cur < -1000) {
				flag = false;
			}
			else {
				sum += cur;
				total++;
			}
		}
		if (!flag) {
			printf("ERROR: %s is not a legal number\n", s.c_str());
		}
	}
	if (total == 0) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (total == 1) {
		printf("The average of 1 number is %.2f\n", sum);
	}
	else {
		printf("The average of %d numbers is %.2f\n", total, sum / total);
	}
	return 0;
}
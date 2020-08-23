#include<iostream>
#include <string>
using namespace std;
int main() {
	int a, b, sum;
	cin >> a >> b;
	sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	string s = to_string(sum);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		cout << s[i];
		if ((i + 1) % 3 == len % 3 && i != len - 1) {
			printf(",");
		}
	}
	return 0;
}
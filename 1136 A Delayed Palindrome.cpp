#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool eq(string s) {
	string r = s;
	reverse_copy(s.begin(), s.end(), r.begin());
	if (r == s) {
		printf("%s is a palindromic number.\n", s.c_str());
		return true;
	}
	return false;
}
int main() {
	string a, sum;
	cin >> a;
	if (eq(a)) {
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		bool flag = true;
		int w = 0, length = a.length();
		for (int j = 0; j < length; j++) {
			int cur = a[j] - '0' + a[length - j - 1] - '0' + w;
			if (cur > 9) {
				w = 1;
				cur -= 10;
			}
			else {
				w = 0;
			}
			sum.insert(sum.begin(), cur + '0');
		}
		if (w == 1) {
			sum.insert(sum.begin(), '1');
		}
		cout << a;
		reverse(a.begin(), a.end());
		printf(" + %s = %s\n", a.c_str(), sum.c_str());
		if (eq(sum)) {
			return 0;
		}
		a.clear();
		a = sum;
		sum.clear();
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}
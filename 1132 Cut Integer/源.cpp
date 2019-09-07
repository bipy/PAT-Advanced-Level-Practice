#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	string  s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		long long original = stoll(s), first = stoll(s.substr(0, s.length() / 2)), second = stoll(s.substr(s.length() / 2));
		if (second > 0 && original % first == 0 && (original / first) % second == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
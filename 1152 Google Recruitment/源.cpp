#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool isPrime(int x) {
	if (x == 0 || x == 1) {
		return false;
	}
	int t = sqrt(x);
	for (int i = 2; i <= t; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	string s;
	int l, n;
	cin >> l >> n;
	cin >> s;
	for (int i = 0; i <= l - n; i++) {
		string temp = s.substr(i, n);
		if (isPrime(stoi(temp))) {
			cout << temp;
			return 0;
		}
	}
	printf("404");
	return 0;
}
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
bool isPrime(int n) {
	if (n <= 1) {	//没有此处过不了第三个测试点
		return false;
	}
	for (int i = sqrt(n); i > 1; i--) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int N, D;
	while (true) {
		cin >> N;
		if (N > 0) {
			cin >> D;
			if (isPrime(N)) {
				string s;
				while (N != 0) {
					s.append(to_string(N % D));
					N /= D;
				}
				int dec = 0;
				for (int i = 0; i < s.length(); i++) {
					dec += (s[s.length() - i - 1] - '0') * pow(D, i);
				}
				isPrime(dec) ? printf("Yes\n") : printf("No\n");
			}
			else {
				printf("No\n");
			}
		}
		else {
			break;
		}
	}
	return 0;
}
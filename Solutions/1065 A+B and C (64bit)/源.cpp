#include<iostream>
using namespace std;
int main() {
	long long int n, a, b, c, sum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		printf("Case #%d: ", i + 1);
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) {
			printf("true\n");
		}
		else if (a < 0 && b < 0 && sum >= 0) {
			printf("false\n");
		}
		else if (sum > c) {
			printf("true\n");
		}
		else {
			printf("false\n");
		}
	}
	return 0;
}
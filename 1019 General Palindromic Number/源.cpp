#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long int n, b, t;
	vector<long long int> ans;
	cin >> n >> b;
	while (n != 0) {
		t = n % b;
		n /= b;
		ans.push_back(t);
	}
	int size = ans.size(), flag = 0;
	for (int i = 0; i < size; i++) {
		if (ans[i] != ans[size - i - 1]) {
			flag = 1;
			break;
		}
	}
	flag == 0 ? printf("Yes\n") : printf("No\n");
	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		it == ans.rend() - 1 ? printf("%lld", *it) : printf("%lld ", *it);
	}
	return 0;
}
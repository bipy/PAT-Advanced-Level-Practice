#include<iostream>
#include<stack>
using namespace std;
int n, m, k, t;
bool process(stack<int> s) {
	int cur = 1;
	bool flag = true;
	for (int j = 0; j < m; j++) {
		scanf("%d", &t);
		while (s.empty() || s.top() != t) {
			s.push(cur++);
			if (s.size() > n || cur > m + 1) {
				flag = false;
				break;
			}
		}
		s.pop();
	}
	if (cur != m + 1) {
		flag = false;
	}
	return flag;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		stack<int> s;
		if (process(s)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
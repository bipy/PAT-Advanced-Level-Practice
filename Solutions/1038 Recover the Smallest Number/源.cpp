#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> ans;
bool cmp(string a, string b) {
	return a + b < b + a;
}
int main() {
	int n, i;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ans.push_back(s);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (i = 0; i < n; i++) {
		if (stoi(ans[i]) != 0) {
			printf("%d", stoi(ans[i++]));
			break;
		}
	}
	if (i != n) {
		while (i < n) {
			cout << ans[i++];
		}
	}
	else {
		printf("0");
	}
	return 0;
}
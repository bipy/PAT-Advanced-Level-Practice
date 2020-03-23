#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<string> v;
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	int i = 0, j = 0;
	string front = v.front(), back = v.back();
	while (i < front.length() && j < back.length()) {
		if (front[i] != back[j]) {
			break;
		}
		j = ++i;
	}
	if (i != 0) {
		string ans = front.substr(0, i);
		reverse(ans.begin(),ans.end());
		cout << ans;
	}
	else {
		printf("nai");
	}
	return 0;
}
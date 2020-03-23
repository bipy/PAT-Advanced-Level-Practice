#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	vector<string> num = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	vector<string> stat = { "Qian ","Bai ","Shi ","" };
	string s, ans;
	cin >> s;
	if (s[0] == '-') {
		ans.append("Fu ");
		s.erase(s.begin());
	}
	while (s.length() % 4 != 0) {
		s.insert(s.begin(), '0');
	}
	for (int i = 0; i < s.length() / 4; i++) {
		string part = s.substr(i * 4, 4);
		bool zero = i == 0 ? false : true;
		int last;
		for (last = 3; last >= 0; last--) {
			if (part[last] != '0') {
				break;
			}
		}
		for (int j = 0; j < 4; j++) {
			int cur = part[j] - '0';
			if (cur != 0) {
				ans.append(num[cur] + " ");
				ans.append(stat[j]);
				zero = true;
			}
			else if (zero && j < last) {
				ans.append(num[0] + " ");
				zero = false;
			}
		}
		int pos = s.length() - (i + 1) * 4;
		if (pos != 0) {
			if (pos % 8 == 0) {
				ans.append("Yi ");
			}
			else if (pos % 4 == 0) {
				ans.append("Wan ");
			}
		}
	}
	if (ans.empty()) {
		ans.append(num[0] + " ");
	}
	ans.erase(ans.end() - 1);//此处用ans.end()也可以在VS上运行，但是在G++运行出错
	cout << ans;
	return 0;
}
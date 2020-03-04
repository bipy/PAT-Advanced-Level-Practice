#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	int length;
	string s, first, second, ans;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'E') {
			first = s.substr(1, i - 1);
			second = s.substr(i + 1);
			break;
		}
	}
	ans = first[0] + first.substr(2);
	//向左移
	if (stoi(second) < 0) {
		length = first.length() + abs(stoi(second));
		while (ans.length() < length - 2) {
			ans = "0" + ans;
		}
		ans = "0." + ans;
	}
	//向右移或不移
	else {
		//找到第一个非零数字
		int eff = 0;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] != '0') {
				eff = i;
				break;
			}
		}
		//移动后有小数点的情况
		if (ans.length() - 1 > stoi(second)) {
			//插入小数点
			ans.insert(ans.begin() + stoi(second) + 1, '.');
			/*
			选择小数点和第一个非零数字中靠前的，截取后半段
			此处插入小数点不会对eff的位置造成影响，因为两个条件互斥：
			1.小数点在前-->对eff造成影响-->选择小数点
			2.小数点在后-->对eff无影响-->选择eff
			*/
			ans = ans.substr(eff < stoi(second) + 1 ? eff : stoi(second));
		}
		//移动后无小数点的情况
		else {
			length = stoi(second) + 1;
			ans = ans.substr(eff);
			while (ans.length() < length - eff) {
				ans.append("0");
			}
		}
	}
	if (s[0] == '-') {
		ans = "-" + ans;
	}
	cout << ans;
	return 0;
}
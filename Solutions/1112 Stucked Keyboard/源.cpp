#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main() {
	int k;
	string input;
	vector<char> output;
	unordered_map<char, bool> check;
	cin >> k >> input;
	// 示意末尾
	input.append("$");
	char temp = input[0];
	int cnt = 0;
	// 计数，如果可以整除k，则为损坏按键 (true)，否则 (false)
	for (int i = 0; i < input.length(); i++) {
		if (temp == input[i]) {
			cnt++;
		}
		else {
			if (cnt % k == 0) {
				check[temp] = true;
			}
			else {
				check[temp] = false;
			}
			cnt = 1;
			temp = input[i];
		}
	}
	// 筛选原始字符串
	for (int i = 0; i < input.length() - 1; i++) {
		output.push_back(input[i]);
		if (check[input[i]]) {
			i += k - 1;
		}
	}
	// 损坏的按键，去重
	for (int i = 0; i < input.length() - 1; i++) {
		if (check[input[i]]) {
			check[input[i]] = false;
			printf("%c", input[i]);
		}
	}
	printf("\n");
	for (auto it = output.begin(); it != output.end(); it++) {
		printf("%c", *it);
	}
	return 0;
}
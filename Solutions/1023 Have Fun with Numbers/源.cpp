#include<iostream>
#include<string>
#define maxN 10
using namespace std;
//long long型不能支持到21位
int main() {
	int count[maxN], ans = 1, w = 0;
	fill(count, count + maxN, 0);
	string input, output;
	cin >> input;
	output = input;
	for (int i = input.length() - 1; i >= 0; i--) {
		int sum = (input[i] - '0') * 2;
		output[i] = to_string(sum % 10 + w)[0];
		sum >= 10 ? w = 1 : w = 0;
	}
	if (w != 1) {
		for (int i = 0; i < input.length(); i++) {
			count[input[i] - '0']++;
			count[output[i] - '0']--;
		}
		for (int i = 0; i < maxN; i++) {
			if (count[i] != 0) {
				ans = 0;
				break;
			}
		}
	}
	else {
		output = '1' + output;
		ans = 0;
	}
	ans == 1 ? printf("Yes\n") : printf("No\n");
	cout << output;
	return 0;
}
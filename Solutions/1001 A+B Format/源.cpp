#include<iostream>
#include <string>
using namespace std;
//以1000为步长找到开头并输出后，后面要一位一位地输出，否则“000”只能输出一个“0”
int main() {
	int a, b, sum;
	cin >> a >> b;
	sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	//字符串方式处理更简单明了
	string s = to_string(sum);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		cout << s[i];
		if ((i + 1) % 3 == len % 3 && i != len - 1) {
			printf(",");
		}
	}
	//以下为数字方式AC
	/*
		int p = 1;
		while (sum / (p * 1000) > 0) {
			p *= 1000;
		}
		printf("%d", (sum / p) % 1000);
		p /= 10;
		int count = 2;
		while (p >= 1) {
			if (++count == 3 && p != 1) {
				printf(",");
				count = 0;
			}
			printf("%d", (sum / p) % 10);
			p /= 10;
		}
	*/
	return 0;
}
#include<iostream>
#include <string>
using namespace std;
//��1000Ϊ�����ҵ���ͷ������󣬺���Ҫһλһλ�����������000��ֻ�����һ����0��
int main() {
	int a, b, sum;
	cin >> a >> b;
	sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	//�ַ�����ʽ�����������
	string s = to_string(sum);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		cout << s[i];
		if ((i + 1) % 3 == len % 3 && i != len - 1) {
			printf(",");
		}
	}
	//����Ϊ���ַ�ʽAC
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
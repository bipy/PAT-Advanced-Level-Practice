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
	//������
	if (stoi(second) < 0) {
		length = first.length() + abs(stoi(second));
		while (ans.length() < length - 2) {
			ans = "0" + ans;
		}
		ans = "0." + ans;
	}
	//�����ƻ���
	else {
		//�ҵ���һ����������
		int eff = 0;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] != '0') {
				eff = i;
				break;
			}
		}
		//�ƶ�����С��������
		if (ans.length() - 1 > stoi(second)) {
			//����С����
			ans.insert(ans.begin() + stoi(second) + 1, '.');
			/*
			ѡ��С����͵�һ�����������п�ǰ�ģ���ȡ����
			�˴�����С���㲻���eff��λ�����Ӱ�죬��Ϊ�����������⣺
			1.С������ǰ-->��eff���Ӱ��-->ѡ��С����
			2.С�����ں�-->��eff��Ӱ��-->ѡ��eff
			*/
			ans = ans.substr(eff < stoi(second) + 1 ? eff : stoi(second));
		}
		//�ƶ�����С��������
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
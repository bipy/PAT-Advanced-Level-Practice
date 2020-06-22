#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int getInteger(char c) {
	if (c - 'a' >= 0) {
		return c - 'a' + 10;
	}
	return c - '0';
}
int main() {
	//freopen("Text.txt", "r", stdin);
	string n[3];
	int tag;
	long long radix, dec[3] = { 0 };
	cin >> n[1] >> n[2] >> tag >> radix;
	int length = n[tag].length();
	for (int i = 0; i < length; i++) {
		dec[tag] += getInteger(n[tag][length - 1 - i]) * pow(radix, i);
	}
	length = n[3 - tag].length();
	long long low = getInteger(*max_element(n[3 - tag].begin(), n[3 - tag].end())) + 1;	//此处必须+1
	long long high = max(low, dec[tag]);
	long long ans;
	int flag = 0;
	while (high >= low) {
		long long mid = (high + low) / 2;
		for (int i = 0; i < length; i++) {
			dec[3 - tag] += getInteger(n[3 - tag][length - 1 - i]) * pow(mid, i);
		}
		if (dec[3 - tag] == dec[tag]) {
			ans = mid;
			high = mid - 1;
			flag = 1;
		}
		else if (dec[3 - tag] > dec[tag] || dec[3 - tag] < 0) {
			dec[3 - tag] = 0;
			high = mid - 1;
		}
		else if (dec[3 - tag] < dec[tag]) {
			dec[3 - tag] = 0;
			low = mid + 1;
		}
	}
	if (flag == 0) {
		cout << "Impossible";
	}
	else {
		cout << ans;
	}
	return 0;
}
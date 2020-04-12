#include<iostream>
#include<string>
#include<vector>
using namespace std;
//���ַ����ж���Ԫ��С�ڸ�����x
long long find(long long left, long long right, long long x, vector<long long>& v) {
	long long mid = left;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] > x) {
			right = mid - 1;
		}
		else if (v[mid] < x) {
			left = mid + 1;
		}
	}
	//���ַ���õĽⲻȷ���Ƿ���ڻ�С��
	//�����һ����������Ϊv[mid]!=x�����Լ�1���Ա�֤���ؽϴ��ֵ
	if (v[mid] < x) {
		mid++;
	}
	return mid;
}
int main() {
	long ans = 0;
	string s;
	cin >> s;
	vector<long long> P, A, T;
	for (long long i = 0; i < s.length(); i++) {
		if (s[i] == 'P') {
			P.push_back(i);
		}
		else if (s[i] == 'A') {
			A.push_back(i);
		}
		else {
			T.push_back(i);
		}
	}
	for (auto it = A.begin(); it != A.end(); it++) {
		long long countP = find(0, P.size() - 1, *it, P);
		long long countT = find(0, T.size() - 1, *it, T);
		ans += (T.size() - countT) * (countP);
	}
	cout << ans % 1000000007;
	return 0;
}
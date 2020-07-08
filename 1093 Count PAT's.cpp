#include<iostream>
#include<string>
#include<vector>
using namespace std;
//二分法求有多少元素小于给定的x
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
	//二分法求得的解不确定是否大于或小于
	//因此做一步修正，因为v[mid]!=x，所以加1可以保证返回较大的值
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
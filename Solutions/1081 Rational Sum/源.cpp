#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	long int num, den;
};
vector<node> v;
//最小公倍数 = 两数之积 / 最大公因数
long int gcd(long int a, long int b) {
	return b ? gcd(b, a % b) : a;
}
bool cmp(const node& a, const node& b) {
	return a.den < b.den;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node temp;
		scanf("%ld/%ld", &temp.num, &temp.den);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	long int num = 0, den = 1;
	for (auto it = v.begin(); it != v.end(); it++) {
		long int g = gcd(it->den, den);
		num = num * (it->den / g) + it->num * (den / g);
		den = den * it->den / g;
	}
	long int g = gcd(num, den);
	num /= g;
	den /= g;
	long int m = num % den, d = num / den;
	if (d != 0 && m != 0) {
		printf("%ld %ld/%ld", d, m, den);
	}
	else if (m == 0) {
		printf("%ld", d);
	}
	else {
		printf("%ld/%ld", num, den);
	}
	return 0;
}
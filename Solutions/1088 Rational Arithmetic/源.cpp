#include<iostream>
#include<string>
#include<vector>
using namespace std;
//分数
struct frac {
	long long integer = 0, n = 0, d = 1;
	bool neg = false;
};
//求最大公因数
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
//取绝对值，记录是否为负数
void posify(frac& x) {
	bool neg = false;
	if (x.integer < 0) {
		x.integer = -x.integer;
		neg = true;
	}
	if (x.n < 0) {
		x.n = -x.n;
		neg = true;
	}
	x.neg = neg;
}
//转化为负数
void negify(frac& x) {
	if (x.neg) {
		x.integer = -x.integer;
		x.n = -x.n;
	}
}
//化简分式
void minify(frac& x) {
	long long m = gcd(x.d, x.n);
	x.n /= m;
	x.d /= m;
}
//通分
void common(frac& a, frac& b) {
	long long m = a.d * b.d / gcd(a.d, b.d);
	a.n = a.n * (m / a.d);
	b.n = b.n * (m / b.d);
	a.d = b.d = m;
}
//格式化
string format(frac x) {
	string rt;
	x.integer = x.n / x.d;
	x.n -= x.integer * x.d;
	minify(x);
	if (x.neg) {
		rt += "(-";
	}
	if (x.integer != 0) {
		rt += to_string(x.integer);
	}
	if (x.integer != 0 && x.n != 0) {
		rt += " ";
	}
	if (x.n != 0) {
		rt += to_string(x.n) + "/" + to_string(x.d);
	}
	if (x.n == 0 && x.integer == 0) {
		rt += "0";
	}
	if (x.neg) {
		rt += ")";
	}
	return rt;
}
//加
string add(frac a, frac b) {
	frac ans;
	common(a, b);
	negify(a);
	negify(b);
	ans.n = a.n + b.n;
	ans.d = a.d;
	posify(ans);
	return format(ans);
}
//减
string sub(frac a, frac b) {
	b.neg = !b.neg;
	return add(a, b);
}
//乘
string mul(frac a, frac b) {
	negify(a);
	negify(b);
	frac ans;
	ans.n = a.n * b.n;
	ans.d = a.d * b.d;
	posify(ans);
	return format(ans);
}
//除
string div(frac a, frac b) {
	if (b.n == 0) {
		return "Inf";
	}
	long long temp = b.n;
	b.n = b.d;
	b.d = temp;
	return mul(a, b);
}
//读取数据初始化
void init(frac& x) {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '/') {
			x.n = stoll(s.substr(0, i));
			x.d = stoll(s.substr(i + 1));
			break;
		}
	}
	posify(x);
	minify(x);
}
int main() {
	frac a, b;
	init(a);
	init(b);
	string first = format(a), second = format(b);
	cout << first + " + " + second + " = " + add(a, b) << endl;
	cout << first + " - " + second + " = " + sub(a, b) << endl;
	cout << first + " * " + second + " = " + mul(a, b) << endl;
	cout << first + " / " + second + " = " + div(a, b) << endl;
	return 0;
}
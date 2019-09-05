#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	s.insert(0, 4 - s.length(), '0');
	do {
		sort(s.begin(), s.end());
		string a = s, b=s;
		reverse_copy(s.begin(), s.end(), b.begin());
		s = to_string(stoi(b) - stoi(a));
		s.insert(0, 4 - s.length(), '0');
		cout << b << " - " << a << " = " << s << endl;
	} while (s != "6174" && s != "0000");
	return 0;
}
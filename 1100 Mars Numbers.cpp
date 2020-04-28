#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#define MAR_RADIX 13
using namespace std;
vector<string> marFisrt = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
vector<string> marSecond = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
unordered_map<string, int> m;
void initMap() {
	for (int i = 0; i < marFisrt.size(); i++) {
		m[marFisrt[i]] = i;
	}
	for (int i = 1; i < marSecond.size(); i++) {
		m[marSecond[i]] = i * MAR_RADIX;
	}
}
int main() {
	initMap();
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);
		if (input[0] == '0') {
			cout << marFisrt[0] << endl;
		}
		else if (input[0] > '0' && input[0] <= '9') {
			string ans = "";
			int earthNum = stoi(input);
			int second = earthNum / MAR_RADIX;
			int first = earthNum % MAR_RADIX;
			if (second != 0) {
				ans.append(marSecond[second]);
			}
			if (second != 0 && first != 0) {
				ans.append(" ");
			}
			if (first != 0) {
				ans.append(marFisrt[first]);
			}
			cout << ans << endl;
		}
		else {
			bool flag = false;
			string first, second;
			for (int i = 0; i < input.length(); i++) {
				if (input[i] == ' ') {
					second = input.substr(0, i);
					first = input.substr(i + 1);
					flag = true;
					break;
				}
			}
			if (flag) {
				cout << m[second] + m[first] << endl;
			}
			else {
				cout << m[input] << endl;
			}
		}
	}
	return 0;
}
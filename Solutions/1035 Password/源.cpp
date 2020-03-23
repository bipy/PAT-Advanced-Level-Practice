#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct user {
	string id, pwd;
};
vector<user> ans;
unordered_map<char, char> trans = {
	{'1','@'},{'0','%'},{'l','L'},{'O','o'}
};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		user temp;
		bool flag = false;
		cin >> temp.id >> temp.pwd;
		for (int j = 0; j < temp.pwd.length(); j++) {
			if (temp.pwd[j] == '1' || temp.pwd[j] == '0' || temp.pwd[j] == 'l' || temp.pwd[j] == 'O') {
				temp.pwd[j] = trans[temp.pwd[j]];
				flag = true;
			}
		}
		if (flag) {
			ans.push_back(temp);
		}
	}
	if (ans.size() == 0) {	//卡在单复数上了2333
		n == 1 ? printf("There is 1 account and no account is modified") : printf("There are %d accounts and no account is modified", n);
	}
	else {
		printf("%d\n", ans.size());
		for (auto it = ans.begin(); it != ans.end(); it++) {
			cout << it->id << " " << it->pwd << endl;
		}
	}
	return 0;
}
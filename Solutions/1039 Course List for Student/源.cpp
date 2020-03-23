#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
unordered_map<string, set<int> > m;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int index, num;
		cin >> index >> num;
		for (int j = 0; j < num; j++) {
			string s;
			cin >> s;
			if (m.count(s) == 0) {
				set<int> temp;
				temp.insert(index);
				m[s] = temp;
			}
			else {
				m[s].insert(index);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m.count(s) == 0) {
			cout << s << " " << 0 << endl;
		}
		else {
			cout << s << " " << m[s].size();
			for(auto it=m[s].begin();it!=m[s].end();it++) {
				cout << " " << *it;
			}
			cout << endl;
		}
	}
	return 0;
}
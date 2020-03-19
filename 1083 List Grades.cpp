#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct student {
	string name, ID;
	int grade;
};
bool cmp(const student& a, const student& b) {
	return a.grade > b.grade;
}
int main() {
	int N, min, max;
	cin >> N;
	vector<student> v;
	bool empty = true;
	for (int i = 0; i < N; i++) {
		string name, ID;
		int grade;
		cin >> name >> ID >> grade;
		v.push_back(student{ name,ID,grade });
	}
	cin >> min >> max;
	sort(v.begin(), v.end(), cmp);
	for (auto it = v.begin(); it != v.end(); it++) {
		if (it->grade >= min && it->grade <= max) {
			cout << it->name << " " << it->ID << endl;
			empty = false;
		}
	}
	if (empty) {
		cout << "NONE" << endl;
	}
	return 0;
}
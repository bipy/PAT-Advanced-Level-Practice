#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;
struct user {
	string id;
	string in;
	string out;
};
bool cmp_in(user a, user b) {
	return a.in < b.in;
}
bool cmp_out(user a, user b) {
	return a.out > b.out;
}
int main() {
	vector<user> record;
	cin >> N;
	for (int i = 0; i < N; i++) {
		user t;
		string tin, tout;
		cin >> t.id >> t.in >> t.out;
		record.push_back(t);
	}
	sort(record.begin(), record.end(), cmp_in);
	cout << record[0].id << " ";
	sort(record.begin(), record.end(), cmp_out);
	cout << record[0].id;
	return 0;
}
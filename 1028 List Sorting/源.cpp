#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	string id, name;
	int score;
};
vector<node> student;
bool cmp1(node a, node b) {
	return a.id < b.id;
}
bool cmp2(node a, node b) {
	if (a.name == b.name) {
		return a.id < b.id;
	}
	return a.name < b.name;
}
bool cmp3(node a, node b) {
	if (a.score == b.score) {
		return a.id < b.id;
	}
	return a.score < b.score;
}
int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.id >> temp.name >> temp.score;
		student.push_back(temp);
	}
	if (c == 1) {
		sort(student.begin(), student.end(), cmp1);
	}
	else if (c == 2) {
		sort(student.begin(), student.end(), cmp2);
	}
	else if (c == 3) {
		sort(student.begin(), student.end(), cmp3);
	}
	for (auto it = student.begin(); it != student.end(); it++) {
		cout << it->id << " " << it->name << " " << it->score << endl;
	}
	return 0;
}
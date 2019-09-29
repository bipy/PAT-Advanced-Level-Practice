#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	string name, id, gender;
	int grade;
};
bool cmp(node a,node b) {
	if(a.gender==b.gender) {
		return a.grade > b.grade;
	}
	return a.gender < b.gender;
}
vector<node> stu;
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		node temp;
		cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
		stu.push_back(temp);
	}
	sort(stu.begin(), stu.end(), cmp);
	bool flag = false;
	if(stu[0].gender=="M") {
		printf("Absent\n");
		flag = true;
	}
	else {
		cout << stu[0].name << " " << stu[0].id << endl;
	}
	if(stu[stu.size()-1].gender=="F") {
		printf("Absent\n");
		flag = true;
	}
	else {
		cout << stu[stu.size() - 1].name << " " << stu[stu.size() - 1].id << endl;
	}
	if(flag) {
		printf("NA");
	}
	else {
		printf("%d", stu[0].grade - stu[stu.size() - 1].grade);
	}
	return 0;
}
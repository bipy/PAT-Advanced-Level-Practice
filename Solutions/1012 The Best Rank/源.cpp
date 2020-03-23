#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef struct student* stu;
struct student {
	int sorce[4], rank[4], best, id;
};
int N, M, cur;
bool cmp(student a, student b) {
	return a.sorce[cur] > b.sorce[cur];
}
int main() {
	//freopen("Text.txt", "r", stdin);
	cin >> N >> M;
	stu list = (stu)malloc(sizeof(struct student) * N);
	for (int i = 0; i < N; i++) {
		cin >> list[i].id >> list[i].sorce[1] >> list[i].sorce[2] >> list[i].sorce[3];
		list[i].sorce[0] = (list[i].sorce[1] + list[i].sorce[2] + list[i].sorce[3]) / 3;
	}
	for (int i = 0; i < 4; i++) {
		cur = i;
		sort(list, list + N, cmp);
		list[0].rank[cur] = 1;
		for (int j = 1; j < N; j++) {
			if (list[j].sorce[cur] == list[j - 1].sorce[cur]) {
				list[j].rank[cur] = list[j - 1].rank[cur];
			}
			else {
				list[j].rank[cur] = j + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		list[i].best = 0;
		for (int j = 0; j < 4; j++) {
			if (list[i].rank[j] < list[i].rank[list[i].best]) {
				list[i].best = j;
			}
		}
	}
	char c[4] = { 'A','C','M','E' };
	unordered_map<int, student> map;
	for (int i = 0; i < N; i++) {
		map[list[i].id] = list[i];
	}
	for (int i = 0; i < M; i++) {
		int check;
		cin >> check;
		if (map.find(check) != map.end()) {
			int best = map[check].best;
			cout << map[check].rank[best] << " " << c[best] << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
	return 0;
}
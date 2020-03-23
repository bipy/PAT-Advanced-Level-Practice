#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct stu {
	int id, total, ac;
	vector<int> score;
};
unordered_map<int, stu> m;
vector<stu> ans;
bool cmp(const stu& a, const stu& b) {
	if (a.total == b.total) {
		if (a.ac == b.ac) {
			return a.id < b.id;
		}
		return a.ac > b.ac;
	}
	return a.total > b.total;
}
int main() {
	int N, K, M;
	cin >> N >> K >> M;
	vector<int> p(K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < M; i++) {
		int uid, pid, point;
		scanf("%d %d %d", &uid, &pid, &point);
		if (m.count(uid) == 0) {
			stu temp;
			temp.id = uid;
			temp.total = 0;
			temp.ac = 0;
			temp.score.resize(K, -2);
			m[uid] = temp;
		}
		pid--;
		m[uid].score[pid] = point > m[uid].score[pid] ? point : m[uid].score[pid];
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		bool show = false;
		for (int i = 0; i < K; i++) {
			int score = it->second.score[i];
			if (score > -1) {
				it->second.total += score;
				if (score == p[i]) {
					it->second.ac++;
				}
				show = true;
			}
			else if (score == -1) {
				it->second.score[i] = 0;
			}
		}
		if (show) {
			ans.push_back(it->second);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	int rank = 1;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (it != ans.begin() && it->total != (it - 1)->total) {
			rank = it - ans.begin() + 1;
		}
		printf("%d %05d %d", rank, it->id, it->total);
		for (int i = 0; i < K; i++) {
			if (it->score[i] == -2) {
				printf(" -");
			}
			else {
				printf(" %d", it->score[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student {
	int GE, GI, f, ID;
	vector<int> preferred;
};
struct school {
	int quota, ID;
	bool full = false;
	vector<student> admitted;
};
vector<school> ans;
vector<student> v;
int N, M, K, total = 0;
bool cmp(const student& a, const student& b) {
	if (a.f == b.f) {
		return a.GE > b.GE;
	}
	return a.f > b.f;
}

bool cmpID(const student& a, const student& b) {
	return a.ID < b.ID;
}
int main() {
	cin >> N >> M >> K;
	ans.resize(M);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		scanf("%d", &it->quota);
		total += it->quota;
	}
	for (int i = 0; i < M; i++) {
		ans[i].ID = i;
	}
	v.resize(N);
	for (auto it = v.begin(); it != v.end(); it++) {
		scanf("%d %d", &it->GE, &it->GI);
		it->f = (it->GE + it->GI) / 2;
		it->preferred.resize(K);
		for (int i = 0; i < K; i++) {
			scanf("%d", &it->preferred[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		v[i].ID = i;
	}
	sort(v.begin(), v.end(), cmp);
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int target = v[i].preferred[j];
			if (!ans[target].full) {
				if (ans[target].quota > ans[target].admitted.size()) {
					ans[target].admitted.push_back(v[i]);
					break;
				}
				else {
					student* last = &ans[target].admitted.back();
					if (v[i].f == last->f && v[i].GE == last->GE) {
						ans[target].admitted.push_back(v[i]);
						break;
					}
					else {
						ans[target].full = true;
						count++;
					}
				}
			}
		}
		if (count == M) {
			break;
		}
	}
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (!it->admitted.empty()) {
			sort(it->admitted.begin(), it->admitted.end(), cmpID);
			printf("%d", it->admitted[0].ID);
			for (auto i = it->admitted.begin() + 1; i != it->admitted.end(); i++) {
				printf(" %d", i->ID);
			}
		}
		printf("\n");
	}
	return 0;
}
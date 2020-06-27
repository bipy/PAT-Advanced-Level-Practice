#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 答案
struct record {
	// 最小ID，家庭人数，家庭房产总数，家庭房产总面积
	int min_id, family_count, estate_num, area;
	// 人均面积，人均房产数
	double avg_area, avg_set;
};
// 人与人 邻接表
unordered_map<int, unordered_map<int, bool> > familyMap;
// 有房产的人 表
unordered_map<int, record> estate;
// 查重集
unordered_map<int, bool> visited;
// 答案集
vector<record> ans;

bool cmp(const record& a, const record& b) {
	if (a.avg_area == b.avg_area) {
		return a.min_id < b.min_id;
	}
	return a.avg_area > b.avg_area;
}

void dfs(int cur, record& rt) {
	visited[cur] = true;
	for (auto i = familyMap[cur].begin(); i != familyMap[cur].end(); i++) {
		if (i->first != -1 && !visited[i->first]) {
			// 寻找最小编号
			if (rt.min_id > i->first) {
				rt.min_id = i->first;
			}
			// 如果有房产就把房产算进来
			if (estate.find(i->first) != estate.end()) {
				rt.area += estate[i->first].area;
				rt.estate_num += estate[i->first].estate_num;
			}
			// 家庭成员增加1
			rt.family_count++;
			dfs(i->first, rt);
		}
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int id, fa, mo, k, num, area;
		scanf("%d %d %d %d", &id, &fa, &mo, &k);
		familyMap[id][fa] = familyMap[fa][id] = familyMap[id][mo] = familyMap[mo][id] = true;
		visited[id] = visited[fa] = visited[mo] = false;
		for (int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			familyMap[id][child] = familyMap[child][id] = true;
			visited[child] = false;
		}
		scanf("%d %d", &num, &area);
		estate[id] = record{ id,1,num,area };
	}
	// 查找连通集
	for (auto i = estate.begin(); i != estate.end(); i++) {
		if (i->first != -1 && !visited[i->first]) {
			record rt = i->second;
			dfs(i->first, rt);
			rt.avg_area = (double)rt.area / rt.family_count;
			rt.avg_set = (double)rt.estate_num / rt.family_count;
			ans.push_back(rt);
		}
	}
	// 排序，格式化输出
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%04d %d %.3f %.3f\n", ans[i].min_id, ans[i].family_count, ans[i].avg_set, ans[i].avg_area);
	}
	return 0;
}
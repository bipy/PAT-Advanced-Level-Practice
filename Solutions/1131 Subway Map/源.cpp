#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
// 前提：相邻两站之间只有一条线路
using namespace std;
/* 
struct solution - 一个解
transfer_count - 换乘站计数
normal_count - 地铁站计数
path - 经过的站编号
id - 经过的线路编号
*/
struct solution {
	int transfer_count = 0, normal_count = 0;
	vector<int> path, id;
};
// 邻接表
unordered_map<int, unordered_map<int, int> > m;
// 查重集
vector<bool> visited(10000, false);
// 解集
vector<solution> ans;
// 当前已知解的最小的地铁站数，起始站，终点站
int min_ans, start, dest;

bool cmp(const solution& a, const solution& b) {
	if (a.normal_count == b.normal_count) {
		return a.transfer_count < b.transfer_count;
	}
	return a.normal_count < b.normal_count;
}

// 传入包含所有经过站的 cur_route，将其中的换乘站提取出来加入解集
void get_transfer(solution& cur_route) {
	solution temp;
	temp.normal_count = cur_route.normal_count;
	int pre_route_id = -1;
	for (int i = 0; i < cur_route.path.size() - 1; i++) {
		int cur_route_id = m[cur_route.path[i]][cur_route.path[i + 1]];
		// 如果与下一站之间的线路有变化，则该站是换乘站
		if (pre_route_id != cur_route_id) {
			temp.transfer_count++;
			temp.path.emplace_back(cur_route.path[i]);
			temp.id.emplace_back(cur_route_id);
			pre_route_id = cur_route_id;
		}
	}
	temp.path.emplace_back(dest);
	ans.emplace_back(temp);
}

void dfs(int cur, solution& cur_route, vector<bool>& visited) {
	// 到达终点，更新剪枝标度 min_ans，提取解集
	if (cur == dest) {
		if (min_ans > cur_route.normal_count) {
			min_ans = cur_route.normal_count;
		}
		get_transfer(cur_route);
		return;
	}
	// 剪枝
	if (cur_route.normal_count > min_ans) {
		return;
	}
	// dfs
	for (auto& it : m[cur]) {
		if (!visited[it.first]) {
			visited[it.first] = true;
			cur_route.normal_count++;
			cur_route.path.emplace_back(it.first);
			dfs(it.first, cur_route, visited);
			cur_route.path.pop_back();
			cur_route.normal_count--;
			visited[it.first] = false;
		}
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	int N, M, K, temp;
	cin >> N;
	m.rehash(10000);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		int last;
		scanf("%d", &last);
		for (int j = 1; j < M; j++) {
			scanf("%d", &temp);
			// 记录两站之间的线路编号
			m[last][temp] = m[temp][last] = i;
			last = temp;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		min_ans = INT32_MAX;
		cin >> start >> dest;
		solution route;
		// dfs
		route.path.emplace_back(start);
		visited[start] = true;
		dfs(start, route, visited);
		visited[start] = false;
		// dfs结束，按题目要求对解集中的解排序
		sort(ans.begin(), ans.end(), cmp);
		// 输出
		printf("%d\n", ans[0].normal_count);
		for (int j = 1; j < ans[0].path.size(); j++) {
			printf("Take Line#%d from %04d to %04d.\n", ans[0].id[j - 1], ans[0].path[j - 1], ans[0].path[j]);
		}
		// 清空解集
		ans.clear();
	}
	return 0;
}
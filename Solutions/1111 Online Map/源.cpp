#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node {
	// [0] length
	// [1] time
	int cost[2];
	bool pass = false;
};
struct path {
	string output_format;
	int cost;
};

// 节点数量， 边数量， 起点， 终点
int N, M, source, destination;
// 邻接矩阵
vector<vector<node> > map;
// 查重集
vector<bool> visited;

// DFS 回溯 剪枝
void dfs(int cur, int flag, vector<int>& cost, vector<int>& cur_path, vector<vector<int> >& ans) {
	if (cur == source) {
		ans.push_back(cur_path);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && map[i][cur].pass && map[i][cur].cost[flag] == cost[cur] - cost[i]) {
			cur_path.push_back(i);
			visited[i] = true;
			dfs(i, flag, cost, cur_path, ans);
			visited[i] = false;
			cur_path.pop_back();
		}
	}
}
// 主要算法
path travel(int flag, vector<int>& cost) {
	// Dijkstra
	visited.clear();
	visited.resize(N, false);
	cost[source] = 0;
	for (int i = 0; i < N; i++) {
		int cur = -1, min = INT32_MAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && cost[j] < min) {
				cur = j;
				min = cost[j];
			}
		}
		if (cur == -1) {
			break;
		}
		visited[cur] = true;
		for (int k = 0; k < N; k++) {
			if (!visited[k] && map[cur][k].pass) {
				if (cost[k] > cost[cur] + map[cur][k].cost[flag]) {
					cost[k] = cost[cur] + map[cur][k].cost[flag];
				}
			}
		}
	}
	// DFS
	visited.clear();
	visited.resize(N, false);
	vector<vector<int> > ans;
	vector<int> cur_path;
	cur_path.push_back(destination);
	visited[destination] = true;
	dfs(destination, flag, cost, cur_path, ans);
	// 按题目副条件筛选
	// flag 0/1 区分两种条件
	int min_cost = INT32_MAX, ans_index = 0;
	if (ans.size() > 1) {
		if (flag == 0) {
			for (int i = 0; i < ans.size(); i++) {
				int sum = 0;
				for (int j = ans[i].size() - 1; j > 0; j--) {
					int cur = ans[i][j];
					int next = ans[i][j - 1];
					sum += map[cur][next].cost[1 - flag];
				}
				if (min_cost > sum) {
					min_cost = sum;
					ans_index = i;
				}
			}
		}
		else if (flag == 1) {
			for (int i = 0; i < ans.size(); i++) {
				if (min_cost > ans[i].size()) {
					min_cost = ans[i].size();
					ans_index = i;
				}
			}
		}
	}
	// 处理数据，按输出格式拼接 string
	path rt;
	rt.cost = cost[destination];
	rt.output_format.append(to_string(source));
	for (auto it = ans[ans_index].rbegin() + 1; it != ans[ans_index].rend(); it++) {
		rt.output_format.append(" -> ");
		rt.output_format.append(to_string(*it));
	}
	rt.output_format.append("\n");
	return rt;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	cin >> N >> M;
	map.resize(N, vector<node>(N));
	for (int i = 0; i < M; i++) {
		int v1, v2, one_way, cur_length, cur_time;
		scanf("%d %d %d %d %d", &v1, &v2, &one_way, &cur_length, &cur_time);
		map[v1][v2] = node{ cur_length,cur_time,true };
		map[v2][v1] = node{ cur_length,cur_time,one_way == 0 };
	}
	vector<int> dist(N, INT32_MAX), time(N, INT32_MAX);
	cin >> source >> destination;
	// 读入数据结束，开始计算
	path shortest_path = travel(0, dist);
	path fastest_path = travel(1, time);
	// 计算结束，格式化输出
	printf("Distance = %d", shortest_path.cost);
	if (shortest_path.output_format != fastest_path.output_format) {
		printf(": ");
		cout << shortest_path.output_format;
	}
	else {
		printf("; ");
	}
	printf("Time = %d: ", fastest_path.cost);
	cout << fastest_path.output_format;
	return 0;
}

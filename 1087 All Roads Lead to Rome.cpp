#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//城市
struct city {
	string name;
	int happiness;
};

//路径
struct route {
	vector<int> path;
	int hSum, hAvg;
};

unordered_map<string, int> m;	//将 string 转化为 int
vector<route> ans;	//存放所有最短路径的容器
vector<vector<int> > cost;	//邻接矩阵
vector<city> cityList;	//将 int 转化为 string
vector<bool> visited;	//查重集合
vector<int> dis;		//各点与起点的距离

string start, destination = "ROM";	//起点，终点
int N, K, costSum;

void dfs(route r, vector<bool> visited) {
	int cur = r.path.back();
	visited[cur] = true;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && cost[i][cur] != -1 && dis[i] + cost[i][cur] == dis[cur]) {
			route temp = r;
			temp.path.push_back(i);
			if (i == 0) {
				ans.push_back(temp);
				return;
			}
			dfs(temp, visited);
		}
	}
}

bool cmp(const route& a, const route& b) {
	if (a.hSum == b.hSum) {
		return a.hAvg > b.hAvg;
	}
	return a.hSum > b.hSum;
}

int main() {
	//读取数据
	//freopen("Text.txt", "r", stdin);
	cin >> N >> K >> start;
	cost.resize(N, vector<int>(N, -1));
	cityList.resize(N);
	m[start] = 0;
	cityList[0] = city{ start,0 };
	for (int i = 1; i < N; i++) {
		string name;
		int happiness;
		cin >> name >> happiness;
		m[name] = i;
		cityList[i] = city{ name,happiness };
	}
	for (int i = 0; i < K; i++) {
		string s1, s2;
		int c1, c2, d;
		cin >> s1 >> s2 >> d;
		c1 = m[s1];
		c2 = m[s2];
		cost[c1][c2] = cost[c2][c1] = d;
	}
	
	//Dijkstra
	visited.resize(N, false);
	dis.resize(N, INT32_MAX);
	dis[0] = 0;
	for (int i = 0; i < N; i++) {
		int cur = -1, min = INT32_MAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dis[j] < min) {
				min = dis[j];
				cur = j;
			}
		}
		if (cur == -1) {
			break;
		}
		visited[cur] = true;
		for (int k = 0; k < N; k++) {
			if (!visited[k] && cost[cur][k] != -1) {
				if (dis[k] > dis[cur] + cost[cur][k]) {
					dis[k] = dis[cur] + cost[cur][k];
				}
			}
		}
	}

	//DFS
	costSum = dis[m[destination]];
	visited.clear();
	visited.resize(N, false);
	route r;
	r.path.push_back(m[destination]);
	dfs(r, visited);

	//数据整理
	for (auto it = ans.begin(); it != ans.end(); it++) {
		it->hSum = 0;
		for (auto i = it->path.begin(); i != it->path.end(); i++) {
			it->hSum += cityList[*i].happiness;
		}
		it->hAvg = (int)(double)it->hSum / (it->path.size()-1);
	}
	sort(ans.begin(), ans.end(), cmp);
	route selected = ans.front();

	//输出
	printf("%d %d %d %d\n", ans.size(), costSum, selected.hSum, selected.hAvg);
	cout << start;
	for (auto it = selected.path.rbegin() + 1; it != selected.path.rend(); it++) {
		cout << "->" << cityList[*it].name;
	}
	return 0;
}

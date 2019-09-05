#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define maxN 1015
#define inf 999999
using namespace std;
struct node {
	double index, minimum, average;
};
int g[maxN][maxN], dis[maxN];
vector<node> station;
bool visited[maxN];
int n, m, k, d;
bool cmp(node a, node b) {
	if (a.minimum == b.minimum) {
		if (a.average == b.average) {
			return a.index < b.index;
		}
		return a.average < b.average;
	}
	return a.minimum > b.minimum;
}
int trans(string& s) {
	if (s[0] == 'G') {
		return stoi(s.substr(1)) + n;
	}
	return stoi(s);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	cin >> n >> m >> k >> d;
	fill(g[0], g[0] + maxN * maxN, inf);
	for (int i = 0; i < k; i++) {
		string a, b;
		int x, y, dist;
		cin >> a >> b >> dist;
		x = trans(a) - 1;
		y = trans(b) - 1;
		g[x][y] = g[y][x] = dist;
	}
	for (int i = n; i < n + m; i++) {
		fill(dis, dis + n + m, inf);
		fill(visited, visited + n + m, false);
		dis[i] = 0;
		visited[i] = false;
		for (int j = 0; j < n + m; j++) {
			int cur = -1, mini = inf;
			for (int v = 0; v < n + m; v++) {
				if (visited[v] == false && dis[v] < mini) {
					cur = v;
					mini = dis[v];
				}
			}
			if (cur == -1) {
				break;
			}
			visited[cur] = true;
			for (int v = 0; v < n + m; v++) {
				if (visited[v] == false && g[cur][v] != inf) {
					dis[v] = min(dis[v], dis[cur] + g[cur][v]);
				}
			}
		}
		double sum = 0, min = inf;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (dis[j] > d) {
				flag = false;
				break;
			}
			sum += dis[j];
			if (min > dis[j]) {
				min = dis[j];
			}
		}
		if (flag) {
			node temp;
			temp.average = sum / n;
			temp.minimum = min;
			temp.index = i - n + 1;
			station.push_back(temp);
		}
	}
	if (station.empty()) {
		cout << "No Solution";
	}
	else {
		sort(station.begin(), station.end(), cmp);
		printf("G%d\n%.1f %.1f", (int)station[0].index, station[0].minimum, station[0].average);
	}
	return 0;
}
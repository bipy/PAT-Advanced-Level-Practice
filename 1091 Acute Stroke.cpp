#include<iostream>
#include<vector>
#include<deque>
using namespace std;
struct node {
	int x, y, z, index;
};
int M, N, L, T;
//三维数组
vector<vector<vector<int> > > brain;
vector<bool> visited;
//线性转三维
node getLoction(int index) {
	int z = index / (M * N);
	int y = index % (M * N) / N;
	int x = index % N;
	return node{ x,y,z,index };
}
//一步BFS
void travel(node next, deque<node>& q) {
	if (next.x < 0 || next.y < 0 || next.z < 0 || next.x >= N || next.y >= M || next.z >= L) {
		return;
	}
	if (brain[next.z][next.y][next.x] == 0) {
		return;
	}
	if (!visited[next.index]) {
		visited[next.index] = true;
		q.push_back(next);
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	cin >> M >> N >> L >> T;
	visited.resize(M * N * L, false);
	brain.resize(L, vector<vector<int> >(M, vector<int>(N, 0)));
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				int point;
				cin >> point;
				brain[i][j][k] = point;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			node n = getLoction(i);
			if (brain[n.z][n.y][n.x] == 0) {
				continue;
			}
			deque<node> q;
			q.push_back(n);
			int count = 0;
			visited[i] = true;
			while (!q.empty()) {
				node cur = q.front();
				travel(node{ cur.x - 1,cur.y,cur.z,cur.index - 1 }, q);
				travel(node{ cur.x + 1,cur.y,cur.z,cur.index + 1 }, q);
				travel(node{ cur.x,cur.y - 1,cur.z,cur.index - N }, q);
				travel(node{ cur.x,cur.y + 1,cur.z,cur.index + N }, q);
				travel(node{ cur.x,cur.y,cur.z - 1,cur.index - N * M }, q);
				travel(node{ cur.x,cur.y,cur.z + 1,cur.index + N * M }, q);
				q.pop_front();
				count++;
			}
			if (count >= T) {
				ans += count;
			}
		}
	}
	cout << ans;
	return 0;
}
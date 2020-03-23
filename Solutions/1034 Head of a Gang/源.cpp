#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define maxN 2010
using namespace std;
struct gang {
	string head;
	int member;
};
bool cmp(gang a, gang b) {
	return a.head < b.head;
}
int n, k, g[maxN][maxN], temp, j = 0, cnt = 0, maxw, index, sum;
bool visited[maxN];
unordered_map<string, int> s2d;
unordered_map<int, string> d2s;
vector<gang> ans;
void dfs(int v) {
	visited[v] = true;
	int weight = 0;
	for (int i = 0; i < j; i++) {
		if (!visited[i] && g[v][i] != 0) {
			cnt++;
			dfs(i);
		}
		if (g[v][i] != 0) {
			weight += g[v][i];
			sum += g[v][i];
		}
	}
	if (weight > maxw) {
		index = v;
		maxw = weight;
	}
}
int main() {
	cin >> n >> k;
	fill(g[0], g[0] + maxN * maxN, 0);
	fill(visited, visited + maxN, false);
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b >> temp;
		if (s2d.count(a) == 0) {
			d2s[j] = a;
			s2d[a] = j++;
		}
		if (s2d.count(b) == 0) {
			d2s[j] = b;
			s2d[b] = j++;
		}
		g[s2d[a]][s2d[b]] = g[s2d[b]][s2d[a]] += temp;
	}
	for (int i = 0; i < j; i++) {
		if (!visited[i]) {
			cnt = 1;
			maxw = -1;
			sum = 0;
			dfs(i);
			if (cnt > 2 && sum/2 > k) {
				gang t;
				t.head = d2s[index];
				t.member = cnt;
				ans.push_back(t);
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << it->head << " " << it->member << endl;
	}
	return 0;
}
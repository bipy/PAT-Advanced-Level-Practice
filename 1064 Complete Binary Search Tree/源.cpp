#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> in, level;
int n, index = 0;
void cbt(int x) {
	if (x * 2 <= n) {
		cbt(x * 2);
	}
	level[x] = in[index++];
	if (x * 2 + 1 <= n) {
		cbt(x * 2 + 1);
	}
}
int main() {
	cin >> n;
	in.resize(n);
	level.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in.begin(), in.end());
	cbt(1);
	for (int i = 1; i < level.size(); i++) {
		i == level.size() - 1 ? printf("%d", level[i]) : printf("%d ", level[i]);
	}
	return 0;
}
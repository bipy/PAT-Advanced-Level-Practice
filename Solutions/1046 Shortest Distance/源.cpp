#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> seq;
int getdistance(int s, int d) {
	int pre = s == 1 ? 0 : seq[s - 1];
	int r = seq[d - 1] - pre, l = seq.back() - r;
	return min(l, r);
}
int main() {
	int n, m, t;
	cin >> n;
	seq.resize(n + 1);
	cin >> seq[1];
	for (int i = 2; i < n + 1; i++) {
		cin >> seq[i];
		seq[i] += seq[i - 1];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		if (s > d) {
			int t = d;
			d = s;
			s = t;
		}
		printf("%d\n", getdistance(s, d));
	}
	return 0;
}